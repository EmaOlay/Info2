#include <string.h>
#include <iostream>
#include <stdio.h>

#include "cadena3.h"

// constructor por omison
cadena::cadena()
{

    m_nchar = 0;
    m_nbytes = SZ_BLOCK;
    m_pstr = new char[m_nbytes];
    strcpy(m_pstr, "");
}

// constructor general
cadena::cadena(const char* str)
{
	
	m_nchar = strlen(str);
	m_nbytes = ((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
	m_pstr = new char[m_nbytes];	// que pasa si no hay memoria???
	strcpy(m_pstr, str);

}



// destructor
cadena::~cadena()
{
    if (m_pstr)		// Hace falta?
      delete (m_pstr);
}




/*=============================================================================

	----------------------- Sobrecarga de operadores --------------------------	

=============================================================================*/

//--- operador de asignación sobrecargado (=)

#if PARTE_2==1
cadena& cadena::operator= (const cadena& cd)
{

    m_nchar = cd.m_nchar;

    if (m_nchar+1 > m_nbytes)
    {
		delete [] m_pstr;
        m_nbytes=((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
        m_pstr = new char[m_nbytes];
    }

    strcpy(m_pstr, cd.m_pstr);

return *this;   
}



//--- operador de asignación sobrecargado (=)
// - Hace falta o se puede omitir? por que?
cadena& cadena::operator= (const char * cd)
{
     m_nchar = strlen(m_pstr);

    if (m_nchar+1 > m_nbytes)
    {
        delete [] m_pstr;
        m_nbytes=((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
		m_pstr = new char[m_nbytes];
    }

    strcpy(m_pstr, cd);

return *this;

}
#endif

/*=============================================================================

	------------------------- Funciones miembro --------------------------	

=============================================================================*/

//-------------------------- set cadena

void cadena::setCadena(const char *str)
{	

	m_nchar = str? strlen(str):0;
	
	if (m_nchar+1 > m_nbytes)	
	{							
		delete [] m_pstr; 
		m_nbytes = ((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
		m_pstr = new char[m_nbytes];
	}
    
	if (str)	strcpy(m_pstr, str);
	else	*m_pstr=0;
}


//-------------------------- print cadena
void cadena::prtCadena() const
{
	std::cout << m_pstr<< std::endl;
}
 

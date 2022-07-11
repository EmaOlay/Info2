#include <string.h>
#include <iostream>
#include <stdio.h>

#include "cadena2.h"

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
 

#if 0
//--------- Sobre cargas

//--- operador de asignación sobrecargado (=)
// - en este caso no se puede omitir
cadena cadena::operator= (const cadena& cd)
{
    if(this == &cd)		// analizar !!!!
    {
   //     std::cout <<"gggggggggggg";
        return *this;
    }

    m_nchar = cd.m_nchar;
    if (m_nchar+1 > m_nbytes)		// Que se esta verificando ???
    {
        delete [] m_pstr;
        m_nbytes=m_nchar+1;
        m_pstr = new char[m_nbytes];
    }

    strcpy(m_pstr, cd.m_pstr);

return *this;    // por que retorna una referencia a si misma????
}

//--- operador de asignación sobrecargado (=)
// - en este caso no se puede omitir
/*
cadena cadena::operator= (const char * cd)
{

     std::cout <<"aca estoy\n";
     m_nchar = strlen(cd);
    if (m_nchar+1 > m_nbytes)
    {
        delete [] m_pstr;
        m_nbytes=m_nchar+1;
        m_pstr = new char[m_nbytes];
    }

    strcpy(m_pstr, cd);

return *this;

}*/

// operador de inserción en ostream
std::ostream& operator<< (std::ostream& co, const cadena& cad)
{
    co <<"++ " << cad.m_pstr;
return co;
}
#endif 

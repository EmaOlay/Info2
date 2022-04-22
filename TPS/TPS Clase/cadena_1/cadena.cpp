#include <string.h>
#include <iostream>
#include <stdio.h>

#include "cadena.h"


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


/*=============================================================================

	------------------------- Funciones miembro --------------------------	

=============================================================================*/

//-------------------------- set cadena

void cadena::setCadena(const char *str)
{	

    m_nchar = str? strlen(str):0;	// Que se esta verificando ???
	
    if (m_nchar+1 > m_nbytes)	// Que se esta verificando ???
    {							// Por que +1 ???
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
 

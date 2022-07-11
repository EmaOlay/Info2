#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "cadena5.h"
int cadena::SZ_BLOCK = 128;
/*Metodos static*/
int cadena::get_sz_block(){
    return SZ_BLOCK;
}
bool cadena::set_sz_block(int v_SZ_BLOCK){
    if (v_SZ_BLOCK <=0)
    {
        return false;
    }else if (v_SZ_BLOCK == SZ_BLOCK)
    {
        return true;
    }else{
        SZ_BLOCK = v_SZ_BLOCK;
        return true;
    }
    
    
}

// constructor por omison
cadena::cadena()
{
    mi_metodo_privado(NULL);
}

/*Metodo privado*/
void cadena::mi_metodo_privado(const char* str){
    if (str!=NULL)
    {  
        m_nchar = strlen(str);
        m_nbytes = ((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
        m_pstr = new char[m_nbytes];
        strcpy(m_pstr, str);
    }else {
        m_nchar = 0;
        m_nbytes = SZ_BLOCK;
        m_pstr = new char[m_nbytes];
        strcpy(m_pstr, "");
    }
    
}

// constructor para numeros
cadena::cadena(const double x){
    char* string_asd = new char [10];
    sprintf(string_asd,"%g",x);
    mi_metodo_privado(string_asd);
    delete string_asd;
}
// constructor general
cadena::cadena(const char* str)
{   

    mi_metodo_privado(str);
	/*
	m_nchar = strlen(str);
	m_nbytes = ((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
	m_pstr = new char[m_nbytes];
	strcpy(m_pstr, str);
    */
}

#if PARTE2
cadena::cadena(const cadena& cd)

{

    m_nchar = cd.m_nchar;

    m_nbytes = m_nchar+1; //  != o == a cd.m_nbytes



    m_pstr = new char[m_nbytes];

    strcpy(m_pstr, cd.m_pstr);

}
#endif

// destructor
cadena::~cadena()
{
    if (m_pstr)		// Hace falta?
      delete (m_pstr);
}




/*=============================================================================

	----------------------- Sobrecarga de operadores --------------------------	

=============================================================================*/

//--- operador de asignaci�n sobrecargado (=)


cadena& cadena::operator= (const cadena& cd)
{
#if 0
	if (this == &cd)
		return *this;
#endif
	
	m_nchar = cd.m_nchar;

    if (m_nchar+1 > m_nbytes)	//- eliminado solamente para reproducir la falla
    {
		delete [] m_pstr;
        m_nbytes=((m_nchar/SZ_BLOCK)+1)*SZ_BLOCK;
        m_pstr = new char[m_nbytes];
    }

    strcpy(m_pstr, cd.m_pstr);

return *this;   
}



ostream& operator<< (ostream& co,const cadena& cx){
    co<<cx.m_pstr;
    return co;
}

bool cadena::operator<(const cadena& cx) {
         if(strcmp(m_pstr,cx.m_pstr)<0) {
            return true;
         }         
         return false;
}

bool cadena::operator>(const cadena& cx) {
         if(strcmp(m_pstr,cx.m_pstr)>0) {
            return true;
         }         
         return false;
}

bool cadena::operator==(const cadena& cx) {
         if(strcmp(m_pstr,cx.m_pstr)==0) {
            return true;
         }         
         return false;
}
bool cadena::operator!=(const cadena& cx) {
         if(strcmp(m_pstr,cx.m_pstr)!=0) {
            return true;
         }         
         return false;
}
//--- operador de asignaci�n sobrecargado (=)
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
    //cout<<m_pstr<<endl;
return *this;

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
float cadena::get_num(){
    //me pinta que te devuelva el ascii correspondiente
    if (m_pstr != NULL)
    {
        return(atof(m_pstr));
    }
    return -999;
    
}

int cadena::get_largo_texto(){
    return(strlen(m_pstr));
}
//-------------------------- print cadena
void cadena::prtCadena() const
{
	std::cout << m_pstr<< std::endl;
}
 

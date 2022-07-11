
#ifndef __CADENA_H
#define __CADENA_H

#define SZ_BLOCK 512

class cadena
{
private:
	char* m_pstr;
	int m_nchar; 	// nº de caracteres (sin el '\0')
    int m_nbytes;   // nº de bytes reservados  - ¿para que?
	
public:
    cadena();				// constructor por omision
    cadena(const char*); 	// constructor general
	

    void setCadena(const char*);	// da valor a la variable privada pstr
    void prtCadena() const;


};

#endif


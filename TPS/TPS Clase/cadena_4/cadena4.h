
#ifndef __CADENA_H
#define __CADENA_H
#include <cstddef>
#define SZ_BLOCK 512


class cadena
{
private:
	char* m_pstr;
	int m_nchar; 	// nº de caracteres (sin el '\0')
	int m_nbytes;   // nº de bytes reservados
	
public:
	cadena();		// constructor por omision
	cadena(const char*);	// constructor general
	
	~cadena ();           // destructor

	cadena& operator= (const cadena&);
	cadena& operator= (const char *);

	
	void setCadena(const char*);	// da valor a la variable privada m_pstr
	void prtCadena() const;
};

#endif



#ifndef __CADENA_H
#define __CADENA_H
#include <cstddef>
#define SZ_BLOCK 512

#define PARTE_2 1


class cadena
{
private:
	char* m_pstr;
	int m_nchar; 	// n� de caracteres (sin el '\0')
	int m_nbytes;   // n� de bytes reservados
	
public:
	cadena();		// constructor por omision
	cadena(const char*);	// constructor general
	
	~cadena ();           // destructor

#if PARTE_2==1
	cadena& operator= (const cadena&);

	cadena& operator= (const char *);
	
#endif
	
	
	void setCadena(const char*);	// da valor a la variable privada m_pstr
	void prtCadena() const;
};

#endif



#ifndef __CADENA_H
#define __CADENA_H
#include <cstddef>


using namespace std;

#define PARTE2 0
class cadena
{
private:
	void mi_metodo_privado(const char* str);
	char* m_pstr;
	int m_nchar; 	// n� de caracteres (sin el '\0')
	int m_nbytes;   // n� de bytes reservados
	static int SZ_BLOCK;
	
public:
	cadena();		// constructor por omision
	cadena(const char*);	// constructor general
	cadena(const double x); // cosntructor para numeros
	static int get_sz_block();
	static bool set_sz_block(int SZ_BLOCK = 128);
	int get_largo_texto();
	float get_num();
	
#if PARTE2
	cadena(const cadena&)
;		// constructor de copia
#endif

	~cadena ();           // destructor

	cadena& operator= (const cadena&);
	cadena& operator= (const char *);
	friend ostream& operator<< (ostream &co,const cadena& cx);
	bool operator==(const cadena& cx);
	bool operator!=(const cadena& cx);
	bool operator<(const cadena& cx);
	bool operator>(const cadena& cx);
	void setCadena(const char*);	// da valor a la variable privada m_pstr
	void prtCadena() const;
};

#endif


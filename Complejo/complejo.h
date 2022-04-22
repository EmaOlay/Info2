//#ifndef __COMPLEJO_H__
//#define __COMPLEJO_H__


#define __DBG_COMPLEJO__ 1

/*
Archivo complejo.h
Construccion de la clase complejo, para el manejo de numeros complejos
Version: 0.1 - en construcci�n
Fecha: 03/05/2013
Autor: Curso 2053 - Info II
*/

#include <ostream>
class complejo
{
private:
    double real;		// Almacena la parte real del numero
	double imag;		// Almacena la parte imaginaria del numero

public:
	//-------------------- Constructores
//    complejo(void);         	// C. sin parametros
//    complejo(double , double);  // C. con parametros
   complejo(double =0.0, double =0.0);

    double getReal() const {return real;}        //permite obtener la parte real del complejo
    double getImag() const {return imag;}       //permite obtener la parte imaginaria del complejo
    bool setReal (double xx);	//permite configurarla parte real del complejo
    bool setImag (double xx);	//permite configurarla parte real del complejo


 //   friend void prtComplex(const char *s, const complejo &c);

 //----------------------- sobrecarga de operadores ---
 complejo operator+ (const complejo&);

//  complejo operator+ (const double&);
 // friend complejo operator+ (const double&,const complejo&);
 // friend complejo operator+ (const complejo&,const complejo&);

 // friend std::ostream& operator<< (std::ostream&, const complejo&);

};
//#endif

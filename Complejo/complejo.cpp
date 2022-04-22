/*
Archivo complejo.cpp
Implementacion de la clase complejo definida en complejo.h
Version: 0.1 - en construcci�n
Fecha: 03/05/2013
Autor: Curso 2053 - Info II
*/


#include "complejo.h"
#include <iostream>


// constructor sin parametros
/*
complejo::complejo(void)
{
    real = 0.0;
    imag = 0.0;
}
*/
// constructor con parametros
complejo::complejo(double re, double im)
{
    if (!setReal(re)) real=0;
    if (!setImag(im)) imag=0;
 }


bool complejo::setReal (double xx)
{
    if (xx>-100 && xx<100)
    {
        real=xx;
        return true;
    }
 return false;
}

bool complejo::setImag (double xx)
{
    if (xx>-100 && xx<100)
    {
        imag=xx;
        return true;
    }
return false;
}

// ---------------------- Sobrecarga de Operadores de suma

// operador miembro + sobrecargado

complejo complejo::operator+ (const complejo &a)
{
    complejo suma;
    suma.real = real + a.real;
    suma.imag = imag + a.imag;
    return suma;
}

/*
complejo complejo::operator+ (const double &dd)
{
    complejo suma;
    suma.real = real + dd;
    suma.imag = imag;
    return suma;
}
*/


// Modo friend 1- operador miembro + sobrecargado
/*
complejo operator+ (const double &x,const complejo &a)
{
    complejo suma;
    suma.real = x + a.real;
    suma.imag =  a.imag;
    return suma;
}
*/
/*
complejo operator+ (const complejo &x,const complejo &a)
{
    complejo suma;
    suma.real = x.real + a.real;
    suma.imag = x.imag + a.imag;
    return suma;
}
*/
// operador friend << sobrecargado
/*
std::ostream& operator << (std::ostream& co, const complejo &a)
{
    co << a.real;
    if (a.imag>=0) co<<'+';
    co << a.imag << " i";
    return co;
}
*/


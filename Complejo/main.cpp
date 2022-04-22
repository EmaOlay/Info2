/*
Archivo aplicacion.cpp
Programa para prueba de la clase complejo. Punto de entrada al programa

Version:  - en construccion
Fecha:
Autor: Curso 2053 - Info II
*/

#include <cstdlib>
#include <iostream>
#include "complejo.h"

using namespace std;

void prtComplex(const char *s, complejo &c)
{
   cout << s <<":" << c.getReal();
   if (c.getImag()>=0)
       cout <<" + j"<<c.getImag()<<endl;
   else
       cout <<" - j"<<-c.getImag()<<endl;
}
/*
void prtComplex(const char *s, const complejo &c)
{
   cout << s <<":" << c.real;
   if (c.imag>=0)
       cout <<" + j"<<c.imag<<endl;
   else
       cout <<" - j"<<-c.imag<<endl;
}
*/
int main()
{
complejo cx(5,8.2);
complejo cy;

    prtComplex("cx",cx);
    prtComplex("cy",cy);

    cy.setReal(205.22);
    cy.setImag(-444.44);

    prtComplex("cx",cx);
    prtComplex("cy",cy);

    cy.setReal(20.22);
    cy.setImag(-44.44);

    prtComplex("cx",cx);
    prtComplex("cy",cy);

    cout<<"================"<<endl;

complejo cz;

    cz=cx+cy;
    prtComplex("cz=cx+cy",cz);
	

    return EXIT_SUCCESS;
}

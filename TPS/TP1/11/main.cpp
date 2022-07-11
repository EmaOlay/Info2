
#include "punto.h"

// definición e inicialización de variable static
int Punto::creados = 0;
int Punto::existentes = 0;
double Punto::limite_sup = 1000;
double Punto::limite_inf = -1000;

int main()
{
     Punto *r = new Punto(12.34, 34.56);
     cout << "1. punto r: " << *r << endl;
     cout << "2. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
     delete (r);
     cout << "3. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
}

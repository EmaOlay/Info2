
#include "punto.h"

void ff(void)
{
     Punto p, q, w;
     Punto h(34);
     Punto r = h;
     cout << "a. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
}

// definición e inicialización de variable static
int Punto::creados = 0;
int Punto::existentes = 0;

int main()
{
     cout << "1. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
     Punto p(12.34, -56.78);
     cout << "2. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
     Punto h(p);
     cout << "3. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
     ff();
     cout << "4. Puntos Creados:" << Punto::getCantCreada() << " - Existentes:" << Punto::getCantExistente() << endl;
}

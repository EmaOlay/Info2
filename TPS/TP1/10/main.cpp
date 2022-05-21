
#include "punto.h"

// definición e inicialización de variable static
int Punto::creados = 0;
int Punto::existentes = 0;
double Punto::limite_sup = 1000;
double Punto::limite_inf = -1000;

int main()
{
     Punto r(12.34, 34.56);
     cout << "1. punto r: " << r << endl;
     cout << "2. punto r++: " << r++ << endl;
     cout << "3. punto r: " << r << endl;
     cout << "4. punto ++r: " << ++r << endl;

     /*Como es un post incremento a uno de los dos se le agrega uno despues de hacerse la suma*/
     Punto x(10, 10);
     Punto y;
     y = x++ + x++;
     cout << "5. punto y: " << y << endl;
}

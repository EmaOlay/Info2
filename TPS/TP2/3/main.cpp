#include "Dia.h"

// definición e inicialización de variable static
string Fecha::m_idioma = "ESP";
int Fecha::m_formato = 0;
int main()
{  
    Fecha algo = Fecha("9","7",1816);
    Hitos independencia = Hitos("Independencia Argentina", algo, "Celebracion de la independencia Argentina", 3);
    cout<< independencia <<endl;
    algo.set("5","10",1996);
    Hitos asd = Hitos("Mi cumple", algo, "Celebracion de mi cumple", 300);
    cout<<"hito 1 vs hito2 " << (independencia>asd)<<endl;
    cout<<"hito 2 vs hito1 " << (asd>independencia)<<endl;
    cout<<"hito 2 igual hito1? " << (asd==independencia)<<endl;
}
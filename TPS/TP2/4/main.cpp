#include "Dia.h"

// definición e inicialización de variable static
string Fecha::m_idioma = "ESP";
int Fecha::m_formato = 0;
int main()
{  
    list<Hitos> lista_hitos;
    Fecha algo = Fecha("9","7",1816);
    Hitos independencia = Hitos("Independencia Argentina", algo, "Celebracion de la independencia Argentina", 3);
    algo.set("5","10",1996);
    Hitos asd = Hitos("Mi cumple", algo, "Celebracion de mi cumple", 300);
    algo.set("5","10",1996);
    Hitos asd2 = Hitos("Mi cumple", algo, "Celebracion de mi cumple con otra importancia", 3000);
    //Inicializo la lista
    lista_hitos.push_back(independencia);
    //Inserto sobre la lista
    Inserta_ordenado(lista_hitos,asd);
    Inserta_ordenado(lista_hitos,asd2);
    
    
    showlist(lista_hitos);
}
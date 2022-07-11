#include "Dia.h"

// definición e inicialización de variable static
string Fecha::m_idioma = "ESP";
int Fecha::m_formato = 0;
int main()
{  
    Fecha algo = Fecha("11","1",1996);
    /* Todas pruebas de impresion
    cout<< algo<<endl;
    Fecha::set_formato(1);
    cout<< algo<<endl;
    Fecha::set_formato(2);
    cout<< algo<<endl;
    Fecha::set_formato(3);
    cout<< algo<<endl;
    Fecha::set_Idioma("ENG");
    cout<< algo<<endl;
    Fecha::set_formato(1);
    cout<< algo<<endl;
    Fecha::set_formato(2);
    cout<< algo<<endl;
    Fecha::set_formato(3);
    cout<< algo<<endl;
    cout<< "The day is: "<<algo.getsDia()<<endl;
    Fecha::set_Idioma("ESP");
    cout<< "El dia es: "<<algo.getsDia()<<endl;
    cout<< "El mes es: "<<algo.getsMes()<<endl;
    Fecha::set_Idioma("ENG");
    cout<< "The month is: "<<algo.getsMes()<<endl;
    cout<< "The number of the week is: "<< algo.getxDia()<<endl;
    */
   /* Todas pruebas de add
    cout<< algo<<endl;
    algo.addDias(14);
    cout<< algo<<endl;
    //Me excedo por exceso
    algo.addDias(14);
    cout<< algo<<endl;
    //Me excedo por defecto
    algo.addDias(-31);
    cout<< algo<<endl;
    algo.addMes(7);
    cout<< algo<<endl;
    //Me excedo por exceso
    algo.addMes(6);
    cout<< algo<<endl;
    //Me excedo por defecto
    algo.addMes(-12);
    cout<< algo<<endl;
    algo.addAnio(-12);
    cout<< algo<<endl;
    algo.addAnio(12);
    cout<< algo<<endl;
    //El subs se hace en la logica del add no escribo el codigo salvo que sea MUUYYY necesario
    */
   ///* Todas pruebas de operadores
   Fecha algo2 = Fecha("11","1",1996);
   cout<<"Es igual: "<< (algo==algo2) <<endl;
   cout<< "Es mayor: "<< (algo>algo2) <<endl;
   cout<< "Es menor: "<< (algo<algo2) <<endl;
   cout<< "Es mayor o igual: "<< (algo>=algo2) <<endl;
   cout<< "Es menor o igual: "<< (algo2<=algo) <<endl;
   cout<<"Le sumo 15 dias al 2"<<endl;
   algo2.addDias(15);
   cout<<"comparo al 2 contra el 1"<<endl;
   cout<< "Es mayor: "<< (algo2>algo) <<endl;
   cout<< "Es mayor o igual: "<< (algo2>=algo) <<endl;
   cout<<"comparo al 1 contra el 2"<<endl;
   cout<<"Es igual: "<< (algo==algo2) <<endl;
   cout<< "Es menor: "<< (algo<algo2) <<endl;
   cout<< "Es menor o igual: "<< (algo2<=algo) <<endl;
   //*/

}
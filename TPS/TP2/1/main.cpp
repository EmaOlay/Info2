#include "Dia.h"

int main()
{   /*
    cout<<Dia::valida_dia("32","5",1999)<<endl;
    Dia dia = Dia("31","12",1996);
    cout<< dia << endl;
    // Invalida
    dia.setDia("32");
    cout<< dia << endl;
    // valida
    dia.setDia("30");
    cout<< dia << endl;
    // Invalida
    dia.setMes("-1");
    cout<< dia << endl;
    // valida
    dia.setMes("11");
    cout<< dia << endl;
    // valida
    dia.setAnio(2022);
    cout<< dia << endl;
    // valida
    dia.set("03","02",2000);
    cout<< dia << endl;
    */
   Dia dia = Dia("30","12", 1996);
   cout<< dia <<endl;
   dia++;
   cout<< dia <<endl;
   dia--;
   cout<< dia <<endl;
   dia = dia+33;
   cout<< dia <<endl;
   dia = dia-33;
   cout<< dia <<endl;
   Dia B = Dia("30","12", 1997);
   cout<< B-dia <<endl;
   B = Dia("40","5", 1998);
   cout<< B <<endl;
}
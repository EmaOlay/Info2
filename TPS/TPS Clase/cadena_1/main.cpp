#include <cstdlib>
#include <iostream>
#include "cadena.h"


using namespace std;

void funci ()
{
cadena c1;
cadena c2((char*)"abcdefghijln");


    cout << "imprimimos c1:";
    c1.prtCadena();
    cout << "imprimimos c2:";
    c2.prtCadena();
    cout << "--------------"<<endl;


#if 1
    c1.setCadena("Ahora con datos");
    c2.setCadena(nullptr); //Ahora sin datos
	
	cout << "imprimimos c1:";
    c1.prtCadena();
    cout << "imprimimos c2:";
    c2.prtCadena();
    cout << "--------------"<<endl;

#endif
}


int main()
{
	cout << "iniciamos ..."<<endl;

//	while (1)
		funci();
	
	cout << "Finalizamos ..."<<endl;
return 0;
}

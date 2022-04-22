#include <cstdlib>
#include <iostream>
#include "cadena4.h"

using namespace std;

void funci ()
{
cadena c1("buenos dias gente de");
cadena c2("Informatica II");

	c1=c2;	// asignacion
	
	cout << "imprimimos c1:";
	c1.prtCadena();
	cout << "imprimimos c2:";
	c2.prtCadena();
	cout << "--------------"<<endl;

	
	c1=c1;
	
	cout << "imprimimos c1:";
	c1.prtCadena();
	cout << "--------------"<<endl;

	
}


int main()
{
	cout << "iniciamos ..."<<endl;
		funci();
	
	cout << "Finalizamos ..."<<endl;
return 0;
}


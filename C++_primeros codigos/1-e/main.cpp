#include <cstdlib>
#include <iostream>
#include "temperatura.h"


using std::cout;
using std::cin;
using std::endl;
#define PRESS_KEY {std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();}

// Main de Pruebas -----

//void myprint (Temperatura &tt) - modificado 1-e
void myprint (const Temperatura &tt) // modificado 1-e
{
    cout << "\nTemp X:"<<tt.getTemp('C')<<" °C";
	  cout << " : "<<tt.getTemp('F')<<" °F"<<endl;
}

int main()
{
Temperatura tx (110.22,'F');

    myprint (tx);
    cout << "\nTemp ():"<<tx.getTemp()<<" °?"<<endl;
  
   tx.setTemp(80.0,'F');
   myprint (tx);

   tx.setTemp(1000.0,'F');
   myprint (tx);
  

	PRESS_KEY;
}


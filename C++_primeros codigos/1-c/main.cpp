#include <cstdlib>
#include <iostream>
#include "temperatura.h"


using std::cout;
using std::cin;
using std::endl;
#define PRESS_KEY {std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();}

// Main de Pruebas -----

int main()
{
Temperatura tx;
    tx.setTemp(155.3,'F');

    cout << "\nTemp X:"<<tx.getTemp('C')<<" °C"<<endl;
	  cout << " : "<<tx.getTemp('F')<<" °F"<<endl;

    cout << "\nTemp ():"<<tx.getTemp()<<" °?"<<endl;
  

	PRESS_KEY;
}


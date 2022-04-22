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
    tx.prtTemp();

  cout << "\nTemp X:"<<tx.getTemp('C')<<" °C"<<endl;
	cout << " : "<<tx.getTemp('F')<<" °F"<<endl;

    tx.setTemp(155.3,'F');
    tx.prtTemp();

	cout << "\nTemp X:"<<tx.getTemp('C')<<" °C"<<endl;
	cout << " : "<<tx.getTemp('F')<<" °F"<<endl;

Temperatura tz(120.55,'C');

  cout << "\nTemp Z:"<<tz.getTemp('C')<<" °C"<<endl;
    cout << " : "<<tz.getTemp('F')<<" °F"<<endl;


	PRESS_KEY;
}


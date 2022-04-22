#include "temperatura.h"
#include <iostream>

Temperatura::Temperatura()
{
	temp=0;
  unit='C';
}


Temperatura::Temperatura(float tt,char unidad)
{
	temp=tt;
    unit=unidad;
}


float Temperatura::getTemp (char unidad) 
{
float aux=0;
    switch (unit)
    {
    case 'C':
        switch (unidad)
        {
        case 'C': aux= temp; break;
        case 'F': aux= 1.8*temp+32; break;
        case 'K': aux= temp+273.15; break;
        }
        break;

    case 'F': 
        switch (unidad)
        {
        case 'C': aux=(temp-32)/1.8; break;
        case 'F': aux=temp; break;
        case 'K': aux=(temp-32)/1.8-273.15; break;
        }
        break;
    case 'K': 
        switch (unidad)
        {
        case 'C': aux=temp-273.15; break;
        case 'F': aux= 1.8*(temp-273.15)+32; break;
        case 'K': aux=temp; break;
        }
        break;

    }
return aux;
}

float Temperatura::getTemp () // agregado en 1-b 
{
  return temp;
}

void Temperatura::setTemp (float tt,char unidad)
{
   temp=tt;
   unit=unidad;
}

void Temperatura::prtTemp ()
{
  std::cout << "Temp:" << temp << " °"<< unit<<std::endl;
}


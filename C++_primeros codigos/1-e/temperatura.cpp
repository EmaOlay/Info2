#include "temperatura.h"
#include <iostream>

Temperatura::Temperatura()
{
	temp=0;
  unit='C';
}


Temperatura::Temperatura(float tt,char unidad)
{
    if (!checkData ( tt,unidad))
      {
        temp=0;
        unit='C';
        return;
      }

  	temp=tt;
    unit=unidad;
}


float Temperatura::getTemp (char unidad) const
{
float aux=0;
    if (unidad==0)
      unidad=unit;

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

//--- habría que cambiar el tipo de retorno, no??
// -- tarea para el hogar
void Temperatura::setTemp (float tt,char unidad)
{

   if (!checkData ( tt,unidad)) //----- modificado 1-d
        return;

   temp=tt;
   unit=unidad;
}

void Temperatura::prtTemp () const
{
  std::cout << "Temp:" << temp << " °"<< unit<<std::endl;
}

//---- Agregado en 1-d (metodo privado)
int Temperatura::checkData (float tt,char unidad) const
{
float tx;
  // comparamos en el campo de °C

  switch (unidad) // llevamos todo a celsius
  {
    case 'F': tx=(tt-32)/1.8; ; break;
    case 'K': tx=tt-273.15;; break;
    case 'C': tx=tt; break;
    default: return 0;  // error
  }

  if (tx<TX_MIN || tx>TX_MAX)
    return 0;  // error

 return 1;
} 

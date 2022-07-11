
#include "punto.h"
#include <iostream>

using namespace std;

Punto::Punto(double x, double y)
{
    if (x < -1000)
    {
        mx = -1000;
    }
    else
    {
        if (x > 1000)
        {
            mx = 1000;
        }
        else
        {
            mx = x;
        }
    }

    if (y < -1000)
    {
        my = -1000;
    }
    else
    {
        if (y > 1000)
        {
            my = 1000;
        }
        else
        {
            my = y;
        }
    }
}

void Punto::setPunto(double x, double y)
{
    if (x < -1000)
    {
        mx = -1000;
    }
    else
    {
        if (x > 1000)
        {
            mx = 1000;
        }
        else
        {
            mx = x;
        }
    }

    if (y < -1000)
    {
        my = -1000;
    }
    else
    {
        if (y > 1000)
        {
            my = 1000;
        }
        else
        {
            my = y;
        }
    }
}

void Punto::setX (double x){
    if (x < -1000)
    {
        mx = -1000;
    }
    else
    {
        if (x > 1000)
        {
            mx = 1000;
        }
        else
        {
            mx = x;
        }
    }
}	
void Punto::setY (double y){
    if (y < -1000)
    {
        my = -1000;
    }
    else
    {
        if (y > 1000)
        {
            my = 1000;
        }
        else
        {
            my = y;
        }
    }
}
//asume que se verifico antes de pasar como parametro
void Punto::set_punto(const Punto pa){
    mx = pa.mx;
    my = pa.my;
}
//asume que se verifico antes de pasar como parametro
void Punto::operator= (const Punto &a)
{
    mx = a.mx;
    my = a.my;
}

Punto Punto::operator+ (const Punto &a){
    
    Punto suma;
    suma.mx = mx + a.mx;
    suma.my = my + a.my;
    if (suma.mx < -1000)
    {
        suma.mx = -1000;
    }
    else
    {
        if (suma.mx > 1000)
        {
            suma.mx = 1000;
        }
    }

    if (suma.my < -1000)
    {
        suma.my = -1000;
    }
    else
    {
        if (suma.my > 1000)
        {
            suma.my = 1000;
        }
    }
    return suma;
}
//la resta es una suma en la que el otro numero es negativo
Punto Punto::operator- (const Punto &a){
    Punto suma;
    suma.mx = mx - a.mx;
    suma.my = my - a.my;
    if (suma.mx < -1000)
    {
        suma.mx = -1000;
    }
    else
    {
        if (suma.mx > 1000)
        {
            suma.mx = 1000;
        }
    }

    if (suma.my < -1000)
    {
        suma.my = -1000;
    }
    else
    {
        if (suma.my > 1000)
        {
            suma.my = 1000;
        }
    }
    return suma;
}
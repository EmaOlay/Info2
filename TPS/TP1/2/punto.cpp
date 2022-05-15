
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
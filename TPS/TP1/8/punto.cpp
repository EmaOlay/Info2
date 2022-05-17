
#include "punto.h"
#include <iostream>
#include <cmath>

using namespace std;

Punto::~Punto(){
    
}

Punto::Punto(double x, double y)
{
    lista.push_back(this);
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

Punto operator+(int i, const Punto &a){
    Punto res;
    res = a;
    res.setX(i + res.getX());
    return res;
}

Punto operator-(int i, const Punto &a){
    Punto res;
    res = a;
    res.setX(i - res.getX());
    return res;
}

bool Punto::operator== (const Punto &a){
    
    if (mx == a.mx && my == a.my)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Punto::operator!= (const Punto &a){
    
    if (mx == a.mx && my == a.my)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

bool Punto::operator> (const Punto &a){
    double this_dist = pow(mx,2) + pow(my,2);
    double a_dist = pow(a.mx,2) + pow(a.my,2);
    if (this_dist > a_dist)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Punto::operator< (const Punto &a){
    double this_dist = pow(mx,2) + pow(my,2);
    double a_dist = pow(a.mx,2) + pow(a.my,2);
    if (this_dist < a_dist)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

ostream& operator<<(ostream& os, const Punto &a){
    os << '(' << a.getX() << ';' << a.getY() << ')';
    return os;
}

istream& operator>> (istream& is, Punto& a)
{
    double x,y;
    cout<<"x:";
    is>> x;
    a.setX(x);
    cout<<"y:";
    is>> y;
    a.setY(y);
    return is;
}

#include "punto.h"
#include <iostream>
#include <cmath>

using namespace std;

Punto::Punto(const Punto& Punto){
    creados++;
    existentes++;
    mx=Punto.mx;
    my=Punto.my;
}


Punto::Punto(double x, double y)
{
    creados++;
    existentes++;
    if (x < Punto::limite_inf)
    {
        mx = Punto::limite_inf;
    }
    else
    {
        if (x > Punto::limite_sup)
        {
            mx = Punto::limite_sup;
        }
        else
        {
            mx = x;
        }
    }

    if (y < Punto::limite_inf)
    {
        my = Punto::limite_inf;
    }
    else
    {
        if (y > Punto::limite_sup)
        {
            my = Punto::limite_sup;
        }
        else
        {
            my = y;
        }
    }
}

void Punto::setLimites (float inf,float sup){
    if (inf>sup)
    {
        cout<<"Limites invalidos"<<endl;
    }
    else
    {
        Punto::limite_inf=inf;
        Punto::limite_sup=sup;
    }
    
}
void Punto::setPunto(Punto& pa){
    if (pa.mx < Punto::limite_inf)
    {
        mx = Punto::limite_inf;
    }
    else
    {
        if (pa.mx > Punto::limite_sup)
        {
            mx = Punto::limite_sup;
        }
        else
        {
            mx = pa.mx;
        }
    }

    if (pa.my < Punto::limite_inf)
    {
        my = Punto::limite_inf;
    }
    else
    {
        if (pa.my > Punto::limite_sup)
        {
            my = Punto::limite_sup;
        }
        else
        {
            my = pa.my;
        }
    }
}

void Punto::setPunto(double x, double y)
{
    if (x < Punto::limite_inf)
    {
        mx = Punto::limite_inf;
    }
    else
    {
        if (x > Punto::limite_sup)
        {
            mx = Punto::limite_sup;
        }
        else
        {
            mx = x;
        }
    }

    if (y < Punto::limite_inf)
    {
        my = Punto::limite_inf;
    }
    else
    {
        if (y > Punto::limite_sup)
        {
            my = Punto::limite_sup;
        }
        else
        {
            my = y;
        }
    }
}

void Punto::setX (double x){
    if (x < Punto::limite_inf)
    {
        mx = Punto::limite_inf;
    }
    else
    {
        if (x > Punto::limite_sup)
        {
            mx = Punto::limite_sup;
        }
        else
        {
            mx = x;
        }
    }
}	
void Punto::setY (double y){
    if (y < Punto::limite_inf)
    {
        my = Punto::limite_inf;
    }
    else
    {
        if (y > Punto::limite_sup)
        {
            my = Punto::limite_sup;
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
    if (suma.mx < Punto::limite_inf)
    {
        suma.mx = Punto::limite_inf;
    }
    else
    {
        if (suma.mx > Punto::limite_sup)
        {
            suma.mx = Punto::limite_sup;
        }
    }

    if (suma.my < Punto::limite_inf)
    {
        suma.my = Punto::limite_inf;
    }
    else
    {
        if (suma.my > Punto::limite_sup)
        {
            suma.my = Punto::limite_sup;
        }
    }
    return suma;
}
//la resta es una suma en la que el otro numero es negativo
Punto Punto::operator- (const Punto &a){
    Punto suma;
    suma.mx = mx - a.mx;
    suma.my = my - a.my;
    if (suma.mx < Punto::limite_inf)
    {
        suma.mx = Punto::limite_inf;
    }
    else
    {
        if (suma.mx > Punto::limite_sup)
        {
            suma.mx = Punto::limite_sup;
        }
    }

    if (suma.my < Punto::limite_inf)
    {
        suma.my = Punto::limite_inf;
    }
    else
    {
        if (suma.my > Punto::limite_sup)
        {
            suma.my = Punto::limite_sup;
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



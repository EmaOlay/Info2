#include "Dia.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool is_bisiesto(int yy){
    if (yy%4==0)
    {
        if (yy%100==0)
        {
            if (yy%400==0)
            {
                return true;
            }
        }else{
            return true;
        }
    }
    return false;    
}

bool Dia::verifica_dia(string dd, string mm,short yy){
    int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_bisiesto(yy))
    {
        dias_x_mes[1]=29;
    }
    int mes = stoi(mm);
    int dia = stoi(dd);
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int anio=1900 + ltm->tm_year;
    // cout << "current Year:" << 1900 + ltm->tm_year<<endl;
    // cout << "Month:" << mes << endl;
    // cout << "day:" << dia << endl;
    if (yy<0 || yy > anio){
        cout<< "Falla por anio"<< endl;
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    // no evaluo anio biciesto
    if (dia < 1 || dia > dias_x_mes[mes-1]){
        cout<< "Falla por dia en el mes"<< endl;
        return false;
    }
    return true;
}
Dia::Dia(string dd, string mm,short yy){
    
    if(verifica_dia(dd,mm,yy)){
        this->dd=dd;
        this->mm=mm;
        this->aa=yy;
    }else{
        //Solo considero fallos por error de mes, dia o anio negativo
        if(yy<1){
            this->aa=1;
            yy=1;            
        }
        if (stoi(mm)>12)
            {
                this->mm=to_string(1);                
            }
        int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (is_bisiesto(yy))
        {
            dias_x_mes[1]=29;
        }
        if (stoi(dd)>dias_x_mes[stoi(mm)])
            {
                this->dd=to_string(1);
                if (stoi(mm)+1>12)
                {
                    this->mm=to_string(1);
                }else{
                    this->mm=to_string(stoi(mm)+1);
                } 
            }
        this->aa=yy;
        cout<<"No es una fecha valida, se cambio"<<endl;
    }
}
bool Dia::setDia(string dd){
    if(verifica_dia(dd,this->mm,this->aa)){
        this->dd=dd;
        return true;
    }else{
        cout<<"No es una fecha valida"<<endl;
        return false;
    }
}

bool Dia::setMes(string mm){
    if(verifica_dia(this->dd,mm,this->aa)){
        this->mm=mm;
        return true;
    }else{
        cout<<"No es una fecha valida"<<endl;
        return false;
    }
}

bool Dia::setAnio(short yy){
    if(verifica_dia(this->dd,this->mm,yy)){
        this->aa=yy;
        return true;
    }else{
        cout<<"No es una fecha valida"<<endl;
        return false;
    }
}

bool Dia::set(string dd,string mm,short aa){
    if(verifica_dia(dd,mm,aa)){
        this->dd=dd;
        this->mm=mm;
        this->aa=aa;
        return true;
    }else{
        cout<<"No es una fecha valida"<<endl;
        return false;
    }
}

bool Dia::valida_dia(string dd, string mm,short yy){
    int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_bisiesto(yy))
    {
        dias_x_mes[1]=29;
    }
    int mes = stoi(mm);
    int dia = stoi(dd);
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int anio=1900 + ltm->tm_year;
    // cout << "current Year:" << 1900 + ltm->tm_year<<endl;
    // cout << "Month:" << mes << endl;
    // cout << "day:" << dia << endl;
    if (yy<0 || yy > anio){
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    if (dia < 1 || dia > dias_x_mes[mes-1]){
        return false;
    }
    return true;
}

Dia Dia::operator++ (int){
    // vector para checkear cantidad de dias
    int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_bisiesto(this->aa))
    {
        dias_x_mes[1]=29;
    }
    int dia = stoi(this->dd);
    int mes = stoi(this->mm);
    if ((dia+1)> dias_x_mes[mes-1])
    {
        this->setDia("1");
        if(mes+1 > 12){
            this->setMes(to_string(1));
            this->setAnio(this->aa +1);
        }else{
            this->setMes(to_string(mes+1));
        }
    }else{
        this->dd = to_string(dia+1);
    }
    return *this;
}

Dia Dia::operator-- (int){
    // vector para checkear cantidad de dias
    int dia = stoi(this->dd);
    int mes = stoi(this->mm);
    if ((dia-1)<1)
    {
        if(mes-1< 0){
            this->setMes(to_string(12));
            this->setAnio(this->aa -1);
        }else{
            this->setMes(to_string(mes-1));
        }
    }else{
        this->dd = to_string(dia-1);
    }
    return *this;
}

Dia Dia::operator+ (int a){
    // vector para checkear cantidad de dias
    int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a_copia = a;
    int dia = stoi(this->dd);
    int mes = stoi(this->mm);
    int anio = this->aa;
    while ((dia+a_copia)> dias_x_mes[mes-1])
    {
        if (is_bisiesto(anio))
        {
            dias_x_mes[1]=29;
        }else{
            dias_x_mes[1]=28;
        }
        int delta = dias_x_mes[mes-1] - dia;
        a_copia = a_copia - delta;
        mes = mes +1;
        if (mes > 12){
            mes=1;
            anio=anio+1;
        }
        dia=0;
    }
    dia=dia + a_copia;
    this->dd = to_string(dia);
    this->mm = to_string(mes);
    this->aa = anio;
    return *this;
}

Dia Dia::operator- (int a){
    // vector para checkear cantidad de dias
    int a_copia = a;
    int dia = stoi(this->dd);
    int mes = stoi(this->mm);
    int anio = this->aa;
    while (a_copia>0)
    {
        int dias_x_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (is_bisiesto(anio))
        {
            dias_x_mes[1]=29;
        }
        if(dia - a_copia<0){
            a_copia=a_copia-dia;
            if (mes -1 < 1)
            {
                anio = anio-1;
                mes=12;
            }else{
                mes = mes -1;
            }
            dia = dias_x_mes[mes-1];
        }else{
            dia=dia - a_copia;
            a_copia = 0;
        }
    }
    
    this->dd = to_string(dia);
    this->mm = to_string(mes);
    this->aa = anio;
    return *this;
}

int Dia::operator- (const Dia a){
    //calculo los dias en a sin considerar biciestos
    int dias_a=0;
    for (int i = 0; i < a.getAnio(); i++)
    {
        if (is_bisiesto(i))
        {
            dias_a+=366;
        }else{
            dias_a+=365;
        }
        
    }
    int dias_x_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_bisiesto(a.getAnio())){
            dias_x_mes[1]=29;
        }
    for (int i = 0; i < stoi(a.getMes()) -1; i++)
    {
        dias_a+=dias_x_mes[i];
    }
    dias_a += stoi(a.getDia());
    //calculo los dias en quien me llamo sin considerar biciestos
    int dias_b=0;
    for (int i = 0; i < this->aa; i++)
    {
        if (is_bisiesto(i))
        {
            dias_b+=366;
        }else{
            dias_b+=365;
        } 
    }
    if (is_bisiesto(this->aa)){
            dias_x_mes[1]=29;
        }else{
            dias_x_mes[1]=28;
    }
    for (int i = 0; i < stoi(this->mm) -1; i++)
    {
        dias_b+=dias_x_mes[i];
    }
    dias_b += stoi(this->dd);
    return dias_b-dias_a;
}

ostream& operator<<(ostream& os, const Dia &a){
    os << a.getDia() << '/' << a.getMes()<< '/' << a.getAnio();
    return os;
}
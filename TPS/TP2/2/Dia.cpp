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

int is_day(string dd, string mm, short yyyy){
    tm time_in = { 0, 0, 0, // second, minute, hour
      stoi(dd), stoi(mm) - 1, yyyy - 1900 }; // 1-based day, 0-based month, year since 1900
    time_t time_temp = std::mktime(&time_in);

    const tm * time_out = localtime(&time_temp);
    //Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}
    return time_out->tm_wday;
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
        cout<<"No es un dia valido, se cambio"<<endl;
    }
}
bool Dia::setDia(string dd){
    if(verifica_dia(dd,this->mm,this->aa)){
        this->dd=dd;
        return true;
    }else{
        cout<<"No es un Dia valido"<<endl;
        return false;
    }
}

bool Dia::setMes(string mm){
    if(verifica_dia(this->dd,mm,this->aa)){
        this->mm=mm;
        return true;
    }else{
        cout<<"No es un Dia valido"<<endl;
        return false;
    }
}

bool Dia::setAnio(short yy){
    if(verifica_dia(this->dd,this->mm,yy)){
        this->aa=yy;
        return true;
    }else{
        cout<<"No es un Dia valido"<<endl;
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
        cout<<"No es un Dia valido"<<endl;
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

Fecha::Fecha(string dd, string mm,short yyyy){
    if(Dia::valida_dia(dd,mm,yyyy)){
        this->set(dd,mm,yyyy);
    }else{
        cout<<"No es un Dia valido"<<endl;
    }
}

string Fecha::getsDia(){
    string Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    if (Fecha::getIdioma() == "ENG")
    {
        string Dias_ENG[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        for (int i = 0; i < 7; i++)
        {
            Dias[i] =Dias_ENG[i];
        }
    }
    int aux = is_day(this->getDia(),this->getMes(),this->getAnio());
    //cout<< aux <<endl;
    return Dias[aux];
}

string Fecha::getsMes(){
    string Meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    if (Fecha::getIdioma() == "ENG")
    {
        string Meses_ENG[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        for (int i = 0; i < 12; i++)
        {
            Meses[i]=Meses_ENG[i];
        }        
    }
    int aux = stoi(this->getMes()) -1;
    return Meses[aux];
}

int Fecha::getxDia(){
    int aux = is_day(this->getDia(),this->getMes(),this->getAnio());
    return aux;
}

bool Fecha::addDias(int a){
    int dias_x_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int dia = stoi(this->getDia());
    int mes = stoi(this->getMes())-1;
    if((dia +a)>dias_x_mes[mes]){
        this->setDia(to_string(dias_x_mes[mes]));
        //retorno false indicando que le trunque la suma
        return false;
    }else{
        this->setDia(to_string(dia +a));
        //retorno true indicando que la suma se hizo correctamente
        return false;
    }
}

bool Fecha::addMes(int a){
    int mes = stoi(this->getMes())-1;
    if((mes +a)>12){
        this->setMes(to_string(12));
        //retorno false indicando que le trunque la suma
        return false;
    }else{
        if(this->setMes(to_string(mes +a))){
            //retorno true indicando que la suma se hizo correctamente
             return true;
        }
        //No se lo hice porque los dias precargados no coinciden para ese mes en particular
        return false;
    }
}

bool Fecha::addAnio(int a){
    //solo verifico que el anio no se haga negativo ni por defecto ni por overflow
    short anio = this->getAnio() + a;
    if(anio<0 || anio >32767){
        //No toco nada
        cout<<"El add anio se romperia no toco nada"<<endl;
        return false;
    }else{
        this->setAnio(anio);
        return true;
    }
}

void Fecha::set_Idioma(string idioma){   
    if(idioma != "ESP" && idioma != "ENG"){
        cout<<"Idioma no soportado, solo \"ESP\" o \"ENG\", "<< idioma <<endl;
    }else{
            m_idioma=idioma;     
    }
}

int Fecha::set_formato(int formato){
    //Acepto formatos de 0-4
    if (formato<0 || formato>4){
        cout<< "No es un formato valido. rango=[0~4]"<<endl;
        return -1;
    }

    m_formato = formato;
    return m_formato;
}

bool Fecha::operator==(const Fecha a){
    if (this->getDia()==a.getDia() && this->getMes()==a.getMes() && this->getAnio()==a.getAnio())
    {
        return true;
    }
    return false;
}

bool Fecha::operator>(const Fecha a){
    if (this->getAnio()>a.getAnio())
    {
        return true;
    }else if (this->getAnio()==a.getAnio()){
        if (stoi(this->getMes())>stoi(a.getMes())){
            return true;
        }else if (stoi(this->getMes())==stoi(a.getMes())){
            if (stoi(this->getDia())>stoi(a.getDia())){
                return true;
            }
            return false;
        }
    }
    return false;
}

bool Fecha::operator<(const Fecha a){
    if (this->getAnio()<a.getAnio())
    {
        return true;
    }else if (this->getAnio()==a.getAnio()){
        if (stoi(this->getMes())<stoi(a.getMes())){
            return true;
        }else if (stoi(this->getMes())==stoi(a.getMes())){
            if (stoi(this->getDia())<stoi(a.getDia())){
                return true;
            }
            return false;
        }
    }
    return false;
}

bool Fecha::operator>=(const Fecha a){
    if (*this > a || *this ==a)
    {
        return true;
    }
    return false;
}

bool Fecha::operator<=(const Fecha a){
    if (*this < a || *this ==a)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Dia &a){
    os << a.getDia() << '/' << a.getMes()<< '/' << a.getAnio();
    return os;
}

ostream& operator<<(ostream& os, const Fecha &a){
    string Meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    string Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    if (Fecha::getIdioma() == "ENG")
    {
        string Dias_ENG[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        string Meses_ENG[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        for (int i = 0; i < 12; i++)
        {
            Meses[i]=Meses_ENG[i];
            if (i<7)
            {
                Dias[i] =Dias_ENG[i];
            }
            
        }        
    }
    if (Fecha::getFormato()==0)
    {
        os << a.getDia() << '/' << a.getMes()<< '/' << a.getAnio();
    }
    if (Fecha::getFormato()==1)
    {
        if (Fecha::getIdioma()=="ESP")
        {
            os << a.getDia() << " de " << Meses[stoi(a.getMes())-1]<< " del anio " << a.getAnio()<<endl;
        }else{
            os <<Meses[stoi(a.getMes())-1]<<' '<< a.getDia() <<" of " << a.getAnio()<<endl;
        } 
    }
    if (Fecha::getFormato()==2)
    {
        os << a.getDia() << "-" << Meses[stoi(a.getMes())-1]<<endl;
    }
    if (Fecha::getFormato()==3)
    {
        int aux=is_day(a.getDia(), a.getMes(), a.getAnio());
        if (Fecha::getIdioma()=="ESP")
        {
            os << Dias[aux]<<", " << a.getDia() << " de " << Meses[stoi(a.getMes())-1]<<endl;
        }else{
            os << Dias[aux]<<", the " << a.getDia() << " of " << Meses[stoi(a.getMes())-1]<<endl;
        }
    }
    return os;
}
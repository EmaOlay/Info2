#include <cstdlib>
#include <iostream>

using namespace std;

class Dia
{
private:
//variables
    string dd;		
	string mm;
    short aa;
//metodos
    bool verifica_dia(string,string,short);
public:
// Constructores
   Dia(string ="1", string ="1",short=1900);
//Destructor
    // ~Dia();
//metodos
    bool setDia(string dd);
    bool setMes(string mm);
    bool setAnio(short yy);
    string getDia() const {return dd;}
    string getMes() const {return mm;}
    short getAnio() const {return aa;}
    bool set(string dd,string mm,short aa);
    static bool valida_dia(string dd, string mm,short yy);
//operadores
//postincremento
    Dia operator++ (int);
    Dia operator-- (int);
    Dia operator+ (int a);
    Dia operator- (int a);
    int operator- (const Dia a);
};
//clase fecha que hereda de dia
class Fecha : public Dia {
    private:
        static string m_idioma;
        static int m_formato;
    public:
    //constructor
    Fecha(string dd, string mm,short yy);
    //Metodos
    string getsDia();
    string getsMes();
    int getxDia();
    //El criterio que adopte para los adds es que en caso de excederse se ajuste al maximo permitido para cada uno
    //tampoco verifico que sean negativos lo unico que verifico es sea valido
    bool addDias(int a);
    bool addMes(int a);
    bool addAnio(int a);
    static void set_Idioma(string idioma);
    static int set_formato(int formato);
    static string getIdioma(){return m_idioma;};
    static int getFormato(){return m_formato;};
    //Operadores
    bool operator==(const Fecha a);
    bool operator>(const Fecha a);
    bool operator<(const Fecha a);
    bool operator>=(const Fecha a);
    bool operator<=(const Fecha a);
};

std::ostream& operator<<(std::ostream& os, const Dia& a);
std::ostream& operator<<(std::ostream& os, const Fecha& a);
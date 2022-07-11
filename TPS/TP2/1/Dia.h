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

std::ostream& operator<<(std::ostream& os, const Dia& a);
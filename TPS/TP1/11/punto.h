#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Punto
{
private:
    double mx;		
	double my;
    static int creados;
    static int existentes;
    static double limite_sup;
    static double limite_inf;
public:
// Constructores
   Punto(double =0.0, double =0.0);
   Punto(const Punto& Punto);
//Destructor
    ~Punto(){existentes--;};
//metodos
    void setPunto(double x, double y);
    void setPunto(Punto& pa);
    void set_punto(const Punto pa);
    Punto getPunto() const{return *this;};
    double getX() const {return mx;};        
    double getY() const {return my;};     
    void setX (double x);	
    void setY (double y);
    static int getCantCreada() {return creados;};
    static int getCantExistente() {return existentes;};
    static void setLimites (float inf,float sup);
    static double getLimiteInf(){return limite_inf;};
    static double getLimiteSup(){return limite_sup ;};

//operadores
void operator= (const Punto &a);
Punto operator+ (const Punto &a);
Punto operator- (const Punto &a);
bool operator== (const Punto &a);
bool operator!= (const Punto &a);
bool operator> (const Punto &a);
bool operator< (const Punto &a);
//preincremento
Punto operator++ ();
//postincremento
Punto operator++ (int);
void * operator new(size_t size);
void operator delete(void * p);

};

std::ostream& operator<<(std::ostream& os, const Punto& a);
std::istream& operator>> (std::istream& is, Punto& a);

Punto operator+(int i, const Punto &a);
Punto operator-(int i, const Punto &a);
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
public:
// Constructores
   Punto(double =0.0, double =0.0);
   Punto(const Punto& Punto);
//Destructor
    ~Punto(){existentes--;};
//metodos
    void setPunto(double x, double y);
    void set_punto(Punto pa);
    Punto getPunto(){return *this;};
    double getX() const {return mx;};        
    double getY() const {return my;};     
    void setX (double x);	
    void setY (double y);
    static int getCantCreada(){return creados;};
    static int getCantExistente() {return existentes;};
//operadores
void operator= (const Punto &a);
Punto operator+ (const Punto &a);
Punto operator- (const Punto &a);
bool operator== (const Punto &a);
bool operator!= (const Punto &a);
bool operator> (const Punto &a);
bool operator< (const Punto &a);

};

std::ostream& operator<<(std::ostream& os, const Punto& a);
std::istream& operator>> (std::istream& is, Punto& a);

Punto operator+(int i, const Punto &a);
Punto operator-(int i, const Punto &a);
class Punto
{
private:
    double mx;		
	double my;		

public:
// Constructores
   Punto(double =0.0, double =0.0);
//metodos
    void setPunto(double x, double y);
    void set_punto(Punto pa);
    Punto getPunto(){return *this;};
    double getX() {return mx;}        
    double getY() {return my;}      
    void setX (double x);	
    void setY (double y);
//operadores
void operator= (const Punto &a);

};
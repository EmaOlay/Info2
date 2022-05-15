class Punto
{
private:
    double mx;		
	double my;		

public:
// Constructores
   Punto(double =0.0, double =0.0);

    void setPunto(double x, double y);
    Punto getPunto(){return *this;};
    double getX() {return mx;}        
    double getY() {return my;}      
    void setX (double x){mx = x;};	
    void setY (double y){my = y;};	
};
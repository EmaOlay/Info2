#ifndef TEMPERATURA_H
#define TEMPERATURA_H


#define TX_MIN -20.0
#define TX_MAX 175.5

struct Temperatura
{
private:
	float temp;	
  char  unit;
  
  int checkData (float tt,char unidad) const;  //--- modificado 1-e
	
public:
  Temperatura();
  Temperatura (float tt,char unidad);
	float getTemp (char unidad=0) const;  //--- modificado 1-e
	
	void  setTemp (float tt,char unidad);
	void  prtTemp () const;             //--- modificado 1-e

};

#endif // TEMPERATURA_H

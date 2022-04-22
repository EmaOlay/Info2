#ifndef TEMPERATURA_H
#define TEMPERATURA_H


#define TX_MIN -20.0
#define TX_MAX 175.5

struct Temperatura
{
private:
	float temp;	
  char  unit;
  
  int checkData (float tt,char unidad);  //--- modificado 1-d
	
public:
  Temperatura();
  Temperatura (float tt,char unidad);
	float getTemp (char unidad=0);  //--- modificado 1-c
	
	void  setTemp (float tt,char unidad);
	void  prtTemp ();

};

#endif // TEMPERATURA_H

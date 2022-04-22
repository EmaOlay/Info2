#ifndef TEMPERATURA_H
#define TEMPERATURA_H

struct Temperatura
{
private:
	float temp;	
  char  unit;
  
public:
  Temperatura();
  Temperatura (float tt,char unidad);
  
	float getTemp (char unidad=0);  //--- modificado 1-c
	float getTemp ();  //--- modificado 1-b

  //--- Error de compilación ----

	void  setTemp (float tt,char unidad);
	void  prtTemp ();

};

#endif // TEMPERATURA_H

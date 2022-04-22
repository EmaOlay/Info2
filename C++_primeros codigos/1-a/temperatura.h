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
	float getTemp (char unidad);
	void  setTemp (float tt,char unidad);
	void  prtTemp ();

};

#endif // TEMPERATURA_H

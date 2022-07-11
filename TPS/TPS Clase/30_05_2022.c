#include <stdio.h>

int func(){
    static int v_est_anterior;
    int aux =readpin();
    if (aux != v_est_anterior)
    {
        v_est_anterior = aux;
        return 1;
    }else{return 0;}
    
}

int detector_de_flanco(){
    static int v_est_anterior=0;
    int aux =readpin();
    if (aux != v_est_anterior && aux== 0)
    {
        v_est_anterior = aux;
        return 1;
    }else{return 0;}
}

void main (void){

    v_est_anterior = 0;//condicion inicial
    func(v_est_anterior);

}
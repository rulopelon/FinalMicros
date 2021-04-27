#include <xc.h>
#include "Pic32Ini.h"
void InicializarRetardo(){
    T3CON = 0;
    TMR3 = 0;
    PR3 = 4999;
}
void Retardo(int milisegundos){
    if(milisegundos<1){
       
    }else{
        T3CON = 0;
        TMR3 = 0;
        T3CON= 0x8000;
        int i;
        for(i= 0; i<milisegundos;i++){
            while(IFS0bits.T3IF == 0);
            IFS0bits.T3IF= 0;
        }
        T3CON = 0;
        TMR3 = 0;
    }
}

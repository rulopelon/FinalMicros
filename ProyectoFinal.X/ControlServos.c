#include <xc.h>
#include <stdint.h>
#include "Pines.h"


#define INCREMENTO_ANGULO 13.88
#define VALOR_REPOSO 3750
void InicializarServos(){
    T2CON = 0;
    TMR2 = 0;
    PR2 = 50000;     // Periodo de 10 ms
    
    T2CON = 0x8010; // T3 ON, Div = 2
    SYSKEY=0xAA996655;
    SYSKEY=0x556699AA;
    RPC6R = 5; // OC1 conectado a RB15
    RPC7R = 5; // OC2 conectado a RB14
    RPC8R = 5; // OC4 conectado a RB13
    RPC9R = 5; // OC1 conectado a RB12
    SYSKEY=0x1CA11CA1;
  
    OC1CON = 0;
    OC1R = 2500;     // Tiempo en alto de 1 ms inicial
    OC1RS = 2500;
    OC1CON = 0x8006; // OC ON, modo PWM sin faltas
    
    OC2CON = 0;
    OC2R = 2500;     // Tiempo en alto de 1 ms inicial
    OC2RS = 2500;
    OC2CON = 0x8006; // OC ON, modo PWM sin faltas
    
    OC3CON = 0;
    OC3R = 2500;     // Tiempo en alto de 1 ms inicial
    OC3RS = 2500;
    OC3CON = 0x8006; // OC ON, modo PWM sin faltas
    
    OC4CON = 0;
    OC4R = 2500;     // Tiempo en alto de 1 ms inicial
    OC4RS = 2500;
    OC4CON = 0x8006; // OC ON, modo PWM sin faltas
} 
void moverServo(int angulo,int servo){
    if(angulo >=-90 && angulo <=90){
    int tiempo = conversionAngulo(angulo);

        switch(servo){
            case 1:
                OC1RS = tiempo;
                break;
            case 2:
                OC2RS = tiempo;
                break;
            case 3:
                OC3RS = tiempo;
                break;
            case 4:
                OC4RS = tiempo;
                break;

        }
    }
    
        

}
int conversionAngulo(int angulo){
    return VALOR_REPOSO+(INCREMENTO_ANGULO*angulo);
    
}

    
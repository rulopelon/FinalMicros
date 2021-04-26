#include <xc.h>
#include <stdint.h>

#define PIN_PULSADOR 5
#define INC_10_GRADOS 139 // cada 139 cuentas se giran 10º

int main(void)
{
    int pulsador_ant, pulsador_act;
    int t_alto = 2500; // Tiempo en alto de la salida (1 ms)
    InicializarServos();
 // Pines de los LEDs como digitales
    ANSELC &= ~0xF;

    LATA = 0; // En el arranque dejamos todas las salidas a 0
    LATB = 0;
    LATC = 0xF; // Apago los LEDs de la placa

 // Pines como salidas excepto RB5
    TRISA = 0;
    TRISB = (1 << PIN_PULSADOR);
    TRISC = 0;
/*
    SYSKEY=0xAA996655;
    SYSKEY=0x556699AA;

    RPC9R = 5; // OC1 conectado a RB12
    SYSKEY=0x1CA11CA1;

    OC3CON = 0;
    OC3R = 2500; // Tiempo en alto de 1 ms inicial
    OC3RS = 2500;
    OC3CON = 0x8006; // OC ON, modo PWM sin faltas

    T2CON = 0;
    TMR2 = 0;
    PR2 = 49999; // Periodo de 20 ms
    T2CON = 0x8010; // T3 ON, Div = 2
*/
    pulsador_ant = (PORTB>>PIN_PULSADOR) & 1;
    while(1){
    // Se lee el estado del pulsador
        pulsador_act = (PORTB>>PIN_PULSADOR) & 1;
        if( (pulsador_act!=pulsador_ant) && (pulsador_act==0) ){
        // Flanco de bajada en la patilla del pulsador
            t_alto += INC_10_GRADOS;
            if(t_alto>5000){
                t_alto = 2500;
            }
            OC2RS = t_alto;
        }
        pulsador_ant = pulsador_act;
    }
}
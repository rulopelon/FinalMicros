#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>
#include "I2cComunication.h"

void InicializarI2C(int velocidad){
    if(velocidad){
        // se trata de 400kbs
        I2C1BRG = 4;
        I2C1CON =0x8000; 
    }else{
        I2C1BRG = 23;
        I2C1CON = 0x8200;
    }
    IFS1bits.I2C1MIF = 0;
    
}
void EnviarStart(void){
    I2C1CONbits.SEN = 1;
    while(IFS1bits.I2C1MIF == 0);
    IFS1bits.I2C1MIF = 0;
}
void EnviarRestart(){
    I2C1CONbits.RSEN = 1;
    while(IFS1bits.I2C1MIF);
    IFS1bits.I2C1MIF = 0;
}
void EnviarStop(){
    I2C1CONbits.PEN = 1;
    while(IFS1bits.I2C1MIF==0);
    IFS1bits.I2C1MIF = 0;
}
int EnviarByte(uint8_t dato){
    I2C1TRN = dato;
    while(IFS1bits.I2C1MIF == 0);
    IFS1bits.I2C1MIF = 0;
    return I2C1STATbits.ACKSTAT;
}
uint8_t LeerByte(uint8_t ack){
    I2C1CONbits.RCEN = 1;
    uint8_t respuesta = I2C1RCV;
    while(IFS1bits.I2C1MIF ==0);
    IFS1bits.I2C1MIF = 0;
    //se devuelve el ack
    I2C1CONbits.ACKDT = ack&1;
    I2C1CONbits.ACKEN = 1;
    while(IFS1bits.I2C1MIF == 0);
    IFS1bits.I2C1MIF = 0;
    
    return respuesta;
}



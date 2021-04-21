#include <xc.h>

#define PINSS
InicializarSPIRecepcion( int frecuencia){
    SPI2CON = 0;
    SPI2CON2 = 0;
    SPI2STAT = 0;
    setFrecuencia(frecuencia);
    SPI2CONbits.CKE = 0;     //para la fase
    SPI2CONbits.MSTEN = 1;
    SPI2CONbits.DISSDO = 1;
    SPI2STATbits.SPIROV = 0;
    //vaciamos el buffer
    int datos = SPI2BUF;
    SPI2CONbits.ON;
}
int setFrecuencia(int frecuencia){
    int respuesta = 0;
   if(frecuencia <2500000){
       //se utiliza el reloj de los perifericos
       SPI2BRG = (5000000/(2*frecuencia))-1;
       SPI2CONbits.MCLKSEL = 1;
   }else if(frecuencia<20000000){
       //se utiliza el del propio chip
       SPI2BRG = (40000000/(2*frecuencia))-1;
       SPI2CONbits.MCLKSEL = 0;
   }
    else if(frecuencia>20000000){
        respuesta = -1;
    }
    return respuesta;
}
int RecibirDato(){
    LATCCLR = 1<<PINSS;
    SPI2BUF = 0;
    while(SPI2STATbits.SPITBF);
    int dato = SPI2BUF;
    while(SPI2STATbits.SPIRBE);
    return dato;
    }
 
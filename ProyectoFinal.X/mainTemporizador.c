#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ControlRobot.h"
#include "TempComunication.h"
#include "Pines.h"



int main(void) {
    InicializacionPines();
InicializarRetardo();
    while(1){
        LATC=0;
        Retardo(1000);
        LATC = 0XFFF;
        Retardo(1000);
    }
    
    
    
}
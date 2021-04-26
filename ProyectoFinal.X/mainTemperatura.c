#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ControlRobot.h"
#include "TempComunication.h"
#include "Pines.h"

int estado_act, estado_ant;// para guardar el estado de los pulsadores
int temperatura_global = 0;
int main(void){
    InicializacionPines();
    InicializarChip();
    
    estado_ant = (PORTB>>PIN_PULSADOR) &1;
    while(1){
        
            int temperatura_act = LeerTemperatura();
            if(temperatura_act<temperatura_global){
                temperatura_global = temperatura_act;
            }
        
        
        //estado_ant = estado_act;
    }
}
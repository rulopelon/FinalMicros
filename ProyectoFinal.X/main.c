/* 
 * File:   main.c
 * Author: gonza
 *
 * Created on 18 de abril de 2021, 21:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ControlRobot.h"
#include "TempComunication.h"
#include "Pines.h"



int estado_act, estado_ant;// para guardar el estado de los pulsadores
int temperatura_global;
int posicion =0;        //para almacenar que posicion tiene la bebida m�s fria
int main(int argc, char** argv) {
    //se inicializan todos los pines de la placa
    InicializacionPines();
    InicializarChip();
    InicializarServos();
    moverOrigen();
    while(1){
        estado_act = (PORTB>>PIN_PULSADOR) &1;
        if(estado_act!= estado_ant &&estado_act ==1){
            //se mueve el servo a la primera posicion
            if((PORTC>>PIN_SENSOR_1)&1){
                moverPosicion1();
                int temperatura_act = LeerTemperatura();
                if(temperatura_act<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 1;
                }
            }
             if((PORTB>>PIN_SENSOR_2)&1){
                moverPosicion2();
                int temperatura_act = LeerTemperatura();
                if(temperatura_act<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 2;
                }
            }
             if((PORTB>>PIN_SENSOR_3)&1){
                moverPosicion3();
                int temperatura_act = LeerTemperatura();
                if(temperatura_act<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 3;
                }
            }
             if((PORTB>>PIN_SENSOR_4)&1){
                moverPosicion4();
                int temperatura_act = LeerTemperatura();
                if(temperatura_act<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 4;
                }
            }
            //una vez se ha terminado con la compribacion de temperatura se se�ala la bebida m�s fr�a
            switch(posicion){
                case 1:
                    //se muestra en los leds
                    moverPosicion1();
                    goto FINAL;
                case 2:
                    moverPosicion2();
                    goto FINAL;
                case 3:
                    moverPosicion3();
                    goto FINAL;
                case 4:
                    moverPosicion4();
                    goto FINAL;
            }
            FINAL:   
            while(((PORTB>>PIN_PULSADOR)&1)==0);
            moverOrigen();
            //se vuelve a empezar
        }
        estado_act = estado_ant;
    }
    return (EXIT_SUCCESS);
}

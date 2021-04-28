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
float temperatura_global =999999;
int posicion =0;        //para almacenar que posicion tiene la bebida más fria
int main(void) {
    //se inicializan todos los pines de la placa
    InicializacionPines();
    InicializarChip();
    InicializarServos();
    InicializarRetardo();
    moverOrigen();
    estado_ant = (PORTB>>PIN_PULSADOR) &1;
    while(1){
        estado_act = (PORTB>>PIN_PULSADOR) &1;
        if(estado_act!= estado_ant &&estado_act == 0){
            //se mueve el servo a la primera posicion
            if(!((PORTC>>PIN_SENSOR_1)&1)){
                moverPosicion1();
                int temperatura_act = LeerTemperatura();
                float temp_celsius = (temperatura_act*0.02) - 273.15;
                if(temp_celsius<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 1;
                }
                Retardo(2000);
            }
             if(!((PORTB>>PIN_SENSOR_2)&1)){
                moverPosicion2();
                int temperatura_act = LeerTemperatura();
                float temp_celsius = (temperatura_act*0.02) - 273.15;
                if(temp_celsius<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 2;
                }
                Retardo(2000);
            }
             if(!((PORTB>>PIN_SENSOR_3)&1)){
                moverPosicion3();
                int temperatura_act = LeerTemperatura();
                float temp_celsius = (temperatura_act*0.02) - 273.15;
                if(temp_celsius<temperatura_global){
                    temperatura_global = temperatura_act;
                    posicion = 3;
                }
                Retardo(2000);
            }
            moverOrigen();
            Retardo(500);
            //una vez se ha terminado con la compribacion de temperatura se señala la bebida más fría
            switch(posicion){
                case 1:
                    //se muestra en los leds
                    moverPosicion1();
                    break;
                case 2:
                    moverPosicion2();
                    break;
                case 3:
                    moverPosicion3();
                    break;
            }
            
            while(((PORTB>>PIN_PULSADOR)&1)==1);
            moverOrigen();
            //se vuelve a empezar
        }
        estado_ant = estado_act;
    }
    return (EXIT_SUCCESS);
}


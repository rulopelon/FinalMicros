#include <xc.h>
#include "Pines.h"

InicializacionPines(){
    // se inicializan todos los pines de los sensores de presencia
    TRISB |= (1<<PIN_SENSOR_1);
    TRISB |= (1<<PIN_SENSOR_2);
    TRISB |= (1<<PIN_SENSOR_3);
    TRISB &= ~(1<<PIN_SCL);
    TRISB &= ~(1<<PIN_SDA);
    LATB  |= (1<<PIN_SCL);
    LATB  |= (1<<PIN_SDA);
    
    ANSELB &= ~(1<<PIN_SENSOR_1);
    ANSELB &= ~(1<<PIN_SENSOR_2);
    ANSELB &= ~(1<<PIN_SENSOR_3);
    ANSELB &= ~(1<<PIN_SCL);
    ANSELB &= ~(1<<PIN_SDA);
    
    TRISC &= ~(1<<PIN_SERVO_1);
    TRISC &= ~(1<<PIN_SERVO_2);
    TRISC &= ~(1<<PIN_SERVO_3);
    TRISC &= ~(1<<PIN_SERVO_4);
    
    ANSELC &= ~(1<<PIN_SERVO_1);
    ANSELC &= ~(1<<PIN_SERVO_2);
    ANSELC &= ~(1<<PIN_SERVO_3);
    ANSELC &= ~(1<<PIN_SERVO_4);
    
    TRISC &= ~(1<<PIN_LED_1);
    TRISC &= ~(1<<PIN_LED_2);
    TRISC &= ~(1<<PIN_LED_3);
    TRISC &= ~(1<<PIN_LED_4);
    
    ANSELC &= ~(1<<PIN_LED_1);
    ANSELC &= ~(1<<PIN_LED_2);
    ANSELC &= ~(1<<PIN_LED_3);
    ANSELC &= ~(1<<PIN_LED_4);
    
    LATB |=(15);
    
    TRISB |= (1<<PIN_PULSADOR);
    ANSELB &= ~(1<<PIN_PULSADOR);
    
}

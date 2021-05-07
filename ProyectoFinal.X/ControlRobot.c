#include <xc.h>
#include "Pines.h"
#include "ControlServos.h"
#include "ControlRobot.h"

void moverPosicion1(){
    moverServo(80,1);
    moverServo(40,2);
    moverServo(92,3);
    moverServo(150,4);
}
void moverPosicion2(){
    moverServo(40,1);
    moverServo(45,2);
    moverServo(95,3);
    moverServo(90,4);
}
void moverPosicion3(){
    moverServo(5,1);
    moverServo(45,2);
    moverServo(94,3);
    moverServo(80,4);
}
void moverOrigen(){
    moverServo(40,1);
    moverServo(90,2);
    moverServo(90,3);
    moverServo(90,4);
}
  


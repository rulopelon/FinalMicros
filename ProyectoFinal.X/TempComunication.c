#include "I2cComunication.h"

#define DIRECCION_DISPOSITIVO 13
#define REGISTRO 2

InicializarChip(){
    InicializarI2C(1);
}
int LeerTemperatura(){
    int respuesta = 0;
    EnviarStart();
    if(EnviarByte(DIRECCION_DISPOSITIVO<<1)){
        respuesta = -1;
        EnviarStop();
    }
    if(EnviarByte(REGISTRO)){
        respuesta = -1;
        EnviarStop();
    }
    EnviarRestart();
    if(EnviarByte(DIRECCION_DISPOSITIVO<<1|1)){
        EnviarStop();
        respuesta = -1;
    }
    respuesta = LeerByte(1);
    EnviarStop();
    
    return respuesta;
    
}

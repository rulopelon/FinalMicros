#include "I2cComunication.h"

#define DIRECCION_DISPOSITIVO 13
#define REGISTRO 2
InicializarChip(){
    InicializarI2C(1);
}
int LeerTemperatura(){
    int respuesta = 0;
    EnviarStart();
    if(EnviaByte(DIRECCION_DISPOSITIVO<<1)){
        respuesta = -1;
        EnviarStop();
    }
    if(EnviaByte(REGISTRO)){
        respuesta = -1;
        EnviarStop();
    }
    EnviarRestart();
    if(EnviaByte(DIRECCION_DISPOSITIVO<<1|1)){
        EnviaStop();
        respuesta = -1;
    }
    respuesta = LeeByte(1);
    EnviaStop();
    
    return respuesta;
    
}

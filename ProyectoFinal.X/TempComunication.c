#include "I2cComunication.h"

#define DIRECCION_DISPOSITIVO  0x5A
#define REGISTRO 0x07

InicializarChip(){
    InicializarI2C(0);
}
int LeerTemperatura(){
    uint16_t respuesta = 0;
    EnviarStart();
    if(EnviarByte(DIRECCION_DISPOSITIVO << 1) != 0){
        respuesta = -1;
        EnviarStop();
        return respuesta;
    }
    if(EnviarByte(REGISTRO) != 0){
        respuesta = -1;
        EnviarStop();
        return respuesta;
    }
    EnviarRestart();
    if(EnviarByte((DIRECCION_DISPOSITIVO << 1) | 1) != 0){
        EnviarStop();
        respuesta = -1;
        return respuesta;
    }
    respuesta = LeerByte(0);
    respuesta |= (LeerByte(0)<<8);
    int  respuesta1 = LeerByte(1);
    EnviarStop();
    
    return respuesta;
    
}

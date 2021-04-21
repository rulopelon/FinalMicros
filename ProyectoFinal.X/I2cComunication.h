#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>

#ifndef I2cComunication    /* Guard against multiple inclusion */
#define I2cComunication

#ifdef	__cplusplus
extern "C" {
#endif
void InicializarI2C(int velocidad);
void EnviarStart();
void EnviarStop();
void EnviarRestart();
int EnviaByte(uint8_t dato);
uint8_t LeeByte(uint8_t ack);

#ifdef	__cplusplus
}
#endif

#endif

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>

#ifndef I2COMUNICATION_H    /* Guard against multiple inclusion */
#define I2COMUNICATION_H
void InicializarI2C(int velocidad);
void EnviarStart(void);
void EnviarStop(void);
void EnviarRestart(void);
int EnviaByte(uint8_t dato);
uint8_t LeeByte(uint8_t ack);

#ifdef	__cplusplus
}
#endif

#endif

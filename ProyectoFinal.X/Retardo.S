#include <xc.h> // Define los registros de los periféricos
.text 
.global Retardo
.ent Retardo 
Retardo:

for: beq a0,zero,fin  
    la t0, T2CON
    sw	zero, 0(t0)
    la t1, TMR2 
    sw zero, 0(t1)
    la t2, IFS0 
    sw zero, 0(t2)
    la t3,  PR2
    ori	t4, zero, 5000
    sw	t4, 0(t3)
    
    li	t4, 0x8000
    sw t4, 0(t0)
while: lw t4, 0(t2)
    srl t4, t4, 9
    andi t4, t4, 1
    bne t4, zero, terminado
    j while
terminado: addi a0,a0,-1
    j for
    
fin:
    
.end Retardo



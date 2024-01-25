#ifndef JSN_SPO4T_H
#define JSN_SPO4T_H
/*
		Библиотека для работы с ультрозвуковыми датчиками.
*/

#include <stm32f411xe.h>
#include <Timer.h>
#include <math.h>

// В таком формате можно указать подкючение ультрозвукового датчика:
// Порт Echo, пин Echo, порт Trig, пин Trig
#define JSN_1 GPIOB, 0, GPIOB, 1

void CMSIS_Init_Timer_Port(void);
void CMSIS_Init_JSN(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG);
float CMSIS_JSN_Start(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG);


#endif 
#ifndef JSN_SPO4T_H
#define JSN_SPO4T_H
/*
		���������� ��� ������ � ��������������� ���������.
*/

#include <stm32f411xe.h>
#include <Timer.h>
#include <math.h>

// � ����� ������� ����� ������� ���������� ��������������� �������:
// ���� Echo, ��� Echo, ���� Trig, ��� Trig
#define JSN_1 GPIOB, 0, GPIOB, 1

void CMSIS_Init_Timer_Port(void);
void CMSIS_Init_JSN(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG);
float CMSIS_JSN_Start(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG);


#endif 
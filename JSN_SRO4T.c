#include <JSN_SPO4T.h>

void CMSIS_Init_Timer_Port(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC |= 0;
	TIM5->ARR |= UINT32_MAX;
	TIM5->CR1 |= TIM_CR1_CEN;
	
	// Запуск тактирования порта А и B:
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}
	

void CMSIS_Init_JSN(GPIO_TypeDef *port_echo, uint8_t ECHO, GPIO_TypeDef *port_trig, uint8_t TRIG)
{	
// JSN: Trig / Echo
	port_trig->MODER |= 0b01 << TRIG * 2;
	port_trig->OTYPER &= ~(1 << TRIG);
	port_trig->OSPEEDR |= 0b11 << TRIG * 2;
	
	port_echo->MODER &= ~(0b11 << ECHO * 2);
	port_echo->PUPDR |= (0b10 << ECHO * 2);
	port_echo->OSPEEDR |= (0b11 << ECHO * 2);
}

float CMSIS_JSN_Start(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG)
{
	uint32_t time = 0;
	port_trig->BSRR |= 1 << TRIG;
	usDelay(10);
	port_trig->BSRR |= 1 << TRIG + 16;
	while(!(port_echo->IDR & (1 << ECHO)))
		;
	TIM5->CNT = 0;
	while(port_echo->IDR & (1 << ECHO)) {
		time = TIM5->CNT;
	}
	float k = 5800;
	return (time / k);
}

# JSN-SR04M-STM32F411

## Бибилиотека для работы с ультрозвуковым датчиком jsn-sr04m для STM32F411.

![изображение](https://github.com/DekartVan/JSN-SR04M-STM32F411/assets/60447026/dcd7b1cb-eacf-4e67-8507-d7f7c1115625)

В библиотеке реализованы 3 функции: 
1. CMSIS_Init_Timer_Port() - запуск таймера TIM5, использующегося для замера времени цикла отправки и приёма УЗ сигнала;
2. CMSIS_Init_JSN(GPIO_TypeDef *port_echo, uint8_t ECHO, GPIO_TypeDef *port_trig, uint8_t TRIG) - инициализация подключения датчика. Параметры - порт, к которому подключен Echo, соответствующая ножка МК, порт, к которому подключен Trig, соответсвующая ему ножка. Для примера объявлено: #define JSN_1 GPIOB, 0, GPIOB, 1.
3. CMSIS_JSN_Start(GPIO_TypeDef* port_echo, uint8_t ECHO, GPIO_TypeDef* port_trig, uint8_t TRIG) - получение расстояния. Получает на вход те же параметры, что и CMSIS_Init_JSN().

Работоспособность тестировалась на stm32F411, разогнанном до 100MHz.

#include <stdint.h>

#include "stmf446xx_gpio_driver.h"

#define LED_PIN_NUM     5
#define BUTTON_PIN_NUM  13

void delay(void);

int main(void)
{
    GPIO_Handle_t gpioLed = {};
    GPIO_Handle_t gpioButton = {};

    gpioLed.pGPIOx = GPIOA;
    gpioLed.pinConfig.GPIO_PinNumber = LED_PIN_NUM;
    gpioLed.pinConfig.GPIO_PinMode = GPIO_MODER_GENERAL_OUTPUT;
    gpioLed.pinConfig.GPIO_PinOpType = GPIO_OTYPER_PP;
    gpioLed.pinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_LOW;
    gpioLed.pinConfig.GPIO_PinPuPdControl = GPIO_PUPDR_NO;

    GPIO_PeriClockControl(GPIOA, 0x01);
    GPIO_Init(&gpioLed);

    gpioButton.pGPIOx = GPIOC;
    gpioButton.pinConfig.GPIO_PinNumber = BUTTON_PIN_NUM;
    gpioButton.pinConfig.GPIO_PinMode = GPIO_MODER_IT_FT;
    gpioButton.pinConfig.GPIO_PinPuPdControl = GPIO_PUPDR_NO;

    GPIO_PeriClockControl(GPIOC, 0x01);
    GPIO_Init(&gpioButton);

    GPIO_IRQInterruptConfig(40, 0x01);

	for(;;);
}

void delay(void) {
    for (int i = 0; i < 500000; i++);
}

void EXTI15_10_IRQHandler(void) {
	GPIO_IRQHandling(BUTTON_PIN_NUM);

	GPIO_ToggleOutputPin(GPIOA, LED_PIN_NUM);
	delay();
}

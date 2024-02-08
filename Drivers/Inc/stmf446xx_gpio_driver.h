#pragma once

#include "stmf446xx.h"

typedef struct {
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOpType;
    uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;

typedef struct {
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t pinConfig;
} GPIO_Handle_t;

#define GPIO_MODER_INPUT            0x00
#define GPIO_MODER_GENERAL_OUTPUT   0x01
#define GPIO_MODER_ALTFUN           0x02
#define GPIO_MODER_ANALOG           0x03
#define GPIO_MODER_IT_FT            0x04
#define GPIO_MODER_IT_RT            0x05
#define GPIO_MODER_IT_RFT           0x06

#define GPIO_OTYPER_PP              0x00
#define GPIO_OTYPER_OD              0x01

#define GPIO_OSPEEDR_LOW            0x00
#define GPIO_OSPEEDR_MED            0x01
#define GPIO_OSPEEDR_FAST           0x02
#define GPIO_OSPEEDR_HIGH           0x03

#define GPIO_PUPDR_NO               0x00
#define GPIO_PUPDR_PU               0x01
#define GPIO_PUPDR_PD               0x02
#define GPIO_PUPDR_RESERVED         0x03

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t enable);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t enable);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t pinNumber);

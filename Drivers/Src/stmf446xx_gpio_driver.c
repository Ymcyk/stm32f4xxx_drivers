#include "stmf446xx_gpio_driver.h"

static uint8_t GPIO_PortIndex(GPIO_RegDef_t *pGPIOx);

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t enable) {
    if (enable) {
        if (GPIOA == pGPIOx) {
            GPIOA_PCLK_EN();
        } else if (GPIOB == pGPIOx) {
            GPIOB_PCLK_EN();
        } else if (GPIOC == pGPIOx) {
            GPIOC_PCLK_EN();
        } else if (GPIOD == pGPIOx) {
            GPIOD_PCLK_EN();
        } else if (GPIOE == pGPIOx) {
            GPIOE_PCLK_EN();
        } else if (GPIOF == pGPIOx) {
            GPIOF_PCLK_EN();
        } else if (GPIOG == pGPIOx) {
            GPIOG_PCLK_EN();
        } else if (GPIOH == pGPIOx) {
            GPIOH_PCLK_EN();
        }
    } else {
        if (GPIOA == pGPIOx) {
            GPIOA_PCLK_DI();
        } else if (GPIOB == pGPIOx) {
            GPIOB_PCLK_DI();
        } else if (GPIOC == pGPIOx) {
            GPIOC_PCLK_DI();
        } else if (GPIOD == pGPIOx) {
            GPIOD_PCLK_DI();
        } else if (GPIOE == pGPIOx) {
            GPIOE_PCLK_DI();
        } else if (GPIOF == pGPIOx) {
            GPIOF_PCLK_DI();
        } else if (GPIOG == pGPIOx) {
            GPIOG_PCLK_DI();
        } else if (GPIOH == pGPIOx) {
            GPIOH_PCLK_DI();
        }
    }
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
    const GPIO_PinConfig_t * const pPinConfig = &(pGPIOHandle->pinConfig);
    GPIO_RegDef_t * const pRegDef = pGPIOHandle->pGPIOx;
    const uint8_t pinNumber = pPinConfig->GPIO_PinNumber;

    if (pPinConfig->GPIO_PinMode <= GPIO_MODER_ANALOG) {
        pRegDef->MODER &= ~(0x3 << (2 * pinNumber));
        pRegDef->MODER |= (pPinConfig->GPIO_PinMode << (2 * pinNumber));
    } else {
        if (pPinConfig->GPIO_PinMode == GPIO_MODER_IT_FT) {
            // 1. EXTI: Configure Falling trigger, disable raising trigger
            EXTI->EXTI_FTSR |= (1 << pinNumber);
            EXTI->EXTI_RTSR &= ~(1 << pinNumber);
        } else if (pPinConfig->GPIO_PinMode == GPIO_MODER_IT_RT) {
            // 1. EXTI: Configure Raising trigger, disable falling trigger
            EXTI->EXTI_RTSR |= (1 << pinNumber);
            EXTI->EXTI_FTSR &= ~(1 << pinNumber);
        } else if (pPinConfig->GPIO_PinMode == GPIO_MODER_IT_RFT) {
            // 1. EXTI: Configure Raising and Falling trigger
            EXTI->EXTI_FTSR |= (1 << pinNumber);
            EXTI->EXTI_RTSR |= (1 << pinNumber);
        }

        // 2. SYSCFG: Port selection - GPIOx <- x
        const uint8_t extiRegIndex = pinNumber / 4;
        const uint8_t extiBitShift = pinNumber % 4;
        const uint8_t portIndex = GPIO_PortIndex(pRegDef);

        SYSCFG->SYSCFG_EXTI[extiRegIndex] |= (portIndex << (extiBitShift * 4));

        // 3. Enable EXTI interrupt delivery
        EXTI->EXTI_IMR |= (1 << pinNumber);
    }

    pRegDef->OTYPER &= ~(0x1 << pinNumber);
    pRegDef->OTYPER |= (pPinConfig->GPIO_PinOpType << pinNumber);

    pRegDef->OSPEEDER &= ~(0x3 << (2 * pinNumber));
    pRegDef->OSPEEDER |= (pPinConfig->GPIO_PinSpeed << (2 * pinNumber));

    pRegDef->PUPDR &= ~(0x3 << (2 * pinNumber));
    pRegDef->PUPDR |= (pPinConfig->GPIO_PinPuPdControl << (2 * pinNumber));

    if (GPIO_MODER_ALTFUN == pPinConfig->GPIO_PinMode) {
        if (pinNumber < 8) {
            pRegDef->AFRL &= ~(0xF << (4 * pinNumber));
            pRegDef->AFRL |= (pPinConfig->GPIO_PinAltFunMode << (4 * pinNumber));
        } else {
            pRegDef->AFRH &= ~(0xF << (4 * pinNumber));
            pRegDef->AFRH |= (pPinConfig->GPIO_PinAltFunMode << (4 * pinNumber));
        }
    }
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {
    if (GPIOA == pGPIOx) {
        GPIOA_REG_RESET();
    } else if (GPIOB == pGPIOx) {
        GPIOB_REG_RESET();
    } else if (GPIOC == pGPIOx) {
        GPIOC_REG_RESET();
    } else if (GPIOD == pGPIOx) {
        GPIOD_REG_RESET();
    } else if (GPIOE == pGPIOx) {
        GPIOE_REG_RESET();
    } else if (GPIOF == pGPIOx) {
        GPIOF_REG_RESET();
    } else if (GPIOG == pGPIOx) {
        GPIOG_REG_RESET();
    } else if (GPIOH == pGPIOx) {
        GPIOH_REG_RESET();
    }
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber) {
    return (uint8_t)((pGPIOx->IDR >> pinNumber) & 0x1);
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) {
    return (uint16_t)(pGPIOx->IDR & 0xFFFF);
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value) {
    if (value) {
        pGPIOx->BSRR |= (1 << pinNumber);
    } else {
        pGPIOx->BSRR |= ((1 << pinNumber) << 0x10);
    }
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value) {
    if (value) {
        pGPIOx->BSRR |= 0xFFFF;
    } else {
        pGPIOx->BSRR |= (0xFFFF << 0x10);
    }
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber) {
    pGPIOx->ODR ^= (1 << pinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enable) {
    if (enable) {
        if (IRQNumber < 32) {
            // ISER0
            (*NVIC_ISER0) |= (1 << IRQNumber);
        } else if (IRQNumber >= 32 && IRQNumber < 64) {
            // ISER1
            (*NVIC_ISER1) |= (1 << (IRQNumber - 32));
        } else if (IRQNumber >= 64 && IRQNumber < 96) {
            // ISER2
            (*NVIC_ISER2) |= (1 << (IRQNumber - 64));
        }
    } else {
        if (IRQNumber < 32) {
            // ICER0
            (*NVIC_ICER0) |= (1 << IRQNumber);
        } else if (IRQNumber >= 32 && IRQNumber < 64) {
            // ICER1
            (*NVIC_ICER1) |= (1 << (IRQNumber - 32));
        } else if (IRQNumber >= 64 && IRQNumber < 96) {
            // ICER2
            (*NVIC_ICER2) |= (1 << (IRQNumber - 64));
        }
    }
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority) {
    const uint8_t iprRegOffset = IRQNumber / 4;
    const uint8_t iprSection = IRQNumber % 4;

    const uint8_t shift = (iprSection * 8) + 4;

    NVIC_IPR_BASE_ADDR[iprRegOffset] |= (IRQPriority << shift);
}

void GPIO_IRQHandling(uint8_t pinNumber) {

}

static uint8_t GPIO_PortIndex(GPIO_RegDef_t *pGPIOx) {
    uint8_t index = 0;

    if (GPIOA == pGPIOx) {
        index = 0;
    } else if (GPIOB == pGPIOx) {
        index = 1;
    } else if (GPIOC == pGPIOx) {
        index = 2;
    } else if (GPIOD == pGPIOx) {
        index = 3;
    } else if (GPIOE == pGPIOx) {
        index = 4;
    } else if (GPIOF == pGPIOx) {
        index = 5;
    } else if (GPIOG == pGPIOx) {
        index = 6;
    } else if (GPIOH == pGPIOx) {
        index = 7;
    }

    return index;
}

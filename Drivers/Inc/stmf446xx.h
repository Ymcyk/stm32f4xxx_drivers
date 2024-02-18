#pragma once

#include <stdint.h>

/*
 * Cortex-M4 specific registers
 */
#define NVIC_ISER0              ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1              ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2              ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER4              ((volatile uint32_t*)0xE000E10C)

#define NVIC_ICER0              ((volatile uint32_t*)0XE000E180)
#define NVIC_ICER1              ((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2              ((volatile uint32_t*)0xE000E188)
#define NVIC_ICER4              ((volatile uint32_t*)0xE000E18C)

#define NVIC_IPR_BASE_ADDR      ((volatile uint32_t*)0xE000E400)

#define NO_PR_BITS_NOT_IMPLEMENTED      4

/*
 * Flash and SRAM memories
 */

#define FLASH_BASE_ADDR         0x08000000U
#define SRAM1_BASE_ADDR         0x20000000U
#define SRAM2_BASE_ADDR         0x2001C000U
#define ROM_BASE_ADDR           0x1FFF0000U
#define SRAM                    SRAM1_BASE_ADDR

/*
 * APBx and AHBx Bus Peripheral base addresses
 */

#define APB1_BASE_ADDR          0x40000000U
#define APB2_BASE_ADDR          0x40010000U
#define AHB1_BASE_ADDR          0x40020000U
#define AHB2_BASE_ADDR          0x50000000U

/*
 * AHB1 Peripherals
 */

#define GPIOA_BASE_ADDR         (AHB1_BASE_ADDR + 0x0000U)
#define GPIOB_BASE_ADDR         (AHB1_BASE_ADDR + 0x0400U)
#define GPIOC_BASE_ADDR         (AHB1_BASE_ADDR + 0x0800U)
#define GPIOD_BASE_ADDR         (AHB1_BASE_ADDR + 0x0C00U)
#define GPIOE_BASE_ADDR         (AHB1_BASE_ADDR + 0x1000U)
#define GPIOF_BASE_ADDR         (AHB1_BASE_ADDR + 0x1400U)
#define GPIOG_BASE_ADDR         (AHB1_BASE_ADDR + 0x1800U)
#define GPIOH_BASE_ADDR         (AHB1_BASE_ADDR + 0x1C00U)
#define RCC_BASE_ADDR           (AHB1_BASE_ADDR + 0x3800U)

/*
 * APB1 Peripherals
 */

#define SPI2_BASE_ADDR          (APB1_BASE_ADDR + 0x3800U)
#define SPI3_BASE_ADDR          (APB1_BASE_ADDR + 0x3C00U)
#define USART2_BASE_ADDR        (APB1_BASE_ADDR + 0x4400U)
#define USART3_BASE_ADDR        (APB1_BASE_ADDR + 0x4800U)
#define UART4_BASE_ADDR         (APB1_BASE_ADDR + 0x4C00U)
#define UART5_BASE_ADDR         (APB1_BASE_ADDR + 0x5000U)
#define I2C1_BASE_ADDR          (APB1_BASE_ADDR + 0x5400U)
#define I2C2_BASE_ADDR          (APB1_BASE_ADDR + 0x5800U)
#define I2C3_BASE_ADDR          (APB1_BASE_ADDR + 0x5C00U)

/*
 * APB2 Peripherals
 */

#define USART1_BASE_ADDR        (APB2_BASE_ADDR + 0x1000U)
#define USART6_BASE_ADDR        (APB2_BASE_ADDR + 0x1400U)
#define SPI1_BASE_ADDR          (APB2_BASE_ADDR + 0x3000U)
#define SPI4_BASE_ADDR          (APB2_BASE_ADDR + 0x3400U)
#define SYSCFG_BASE_ADDR        (APB2_BASE_ADDR + 0x3800U)
#define EXTI_BASE_ADDR          (APB2_BASE_ADDR + 0x3C00U)

/*
 * Structures definitions
 */

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDER;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_RegDef_t;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t __reserved0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t __reserved1;
    uint32_t __reserved2;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t __reserved3;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t __reserved4;
    uint32_t __reserved5;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    uint32_t __reserved6;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t __reserved7;
    uint32_t __reserved8;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t __reserved9;
    uint32_t __reserved10;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
    volatile uint32_t CKGATENR;
    volatile uint32_t DCKCFGR2;
} RCC_RegDef_t;

typedef struct {
    volatile uint32_t EXTI_IMR;
    volatile uint32_t EXTI_EMR;
    volatile uint32_t EXTI_RTSR;
    volatile uint32_t EXTI_FTSR;
    volatile uint32_t EXTI_SWIER;
    volatile uint32_t EXTI_PR;
} EXTI_RegDef_t;

typedef struct {
    volatile uint32_t SYSCFG_MEMRMP;
    volatile uint32_t SYSCFG_PMC;
    volatile uint32_t SYSCFG_EXTI[4];
    volatile uint32_t SYSCFG_CMPCR;
    volatile uint32_t SYSCFG_CFGR;
} SYSCFG_RegDef_t;

typedef struct {
    volatile uint32_t SPI_CR1;
    volatile uint32_t SPI_CR2;
    volatile uint32_t SPI_SR;
    volatile uint32_t SPI_DR;
    volatile uint32_t SPI_CRCPR;
    volatile uint32_t SPI_RXCRCR;
    volatile uint32_t SPI_TXCRCR;
    volatile uint32_t SPI_I2SCFGR;
    volatile uint32_t SPI_I2SPR;
} SPI_RegDef_t;

/*
 * Peripherals definitions
 */

#define GPIOA                   ((GPIO_RegDef_t*) GPIOA_BASE_ADDR)
#define GPIOB                   ((GPIO_RegDef_t*) GPIOB_BASE_ADDR)
#define GPIOC                   ((GPIO_RegDef_t*) GPIOC_BASE_ADDR)
#define GPIOD                   ((GPIO_RegDef_t*) GPIOD_BASE_ADDR)
#define GPIOE                   ((GPIO_RegDef_t*) GPIOE_BASE_ADDR)
#define GPIOF                   ((GPIO_RegDef_t*) GPIOF_BASE_ADDR)
#define GPIOG                   ((GPIO_RegDef_t*) GPIOG_BASE_ADDR)
#define GPIOH                   ((GPIO_RegDef_t*) GPIOH_BASE_ADDR)
#define RCC                     ((RCC_RegDef_t*) RCC_BASE_ADDR)
#define EXTI                    ((EXTI_RegDef_t*) EXTI_BASE_ADDR)
#define SYSCFG                  ((SYSCFG_RegDef_t*) SYSCFG_BASE_ADDR)
#define SPI1                    ((SPI_RegDef_t*) SPI1_BASE_ADDR)
#define SPI2                    ((SPI_RegDef_t*) SPI2_BASE_ADDR)
#define SPI3                    ((SPI_RegDef_t*) SPI3_BASE_ADDR)
#define SPI4                    ((SPI_RegDef_t*) SPI4_BASE_ADDR)

/*
 * Clock enable macros
 */

#define GPIOx_PCLK_EN(SHIFT)    (RCC->AHB1ENR |= (1 << SHIFT))

#define GPIOA_PCLK_EN()         (GPIOx_PCLK_EN(0))
#define GPIOB_PCLK_EN()         (GPIOx_PCLK_EN(1))
#define GPIOC_PCLK_EN()         (GPIOx_PCLK_EN(2))
#define GPIOD_PCLK_EN()         (GPIOx_PCLK_EN(3))
#define GPIOE_PCLK_EN()         (GPIOx_PCLK_EN(4))
#define GPIOF_PCLK_EN()         (GPIOx_PCLK_EN(5))
#define GPIOG_PCLK_EN()         (GPIOx_PCLK_EN(6))
#define GPIOH_PCLK_EN()         (GPIOx_PCLK_EN(7))
#define SYSCFG_PCLK_EN()        (RCC->APB2ENR |= (1 << 14))
#define SPI1_PCLK_EN()          (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()          (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()          (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()          (RCC->APB2ENR |= (1 << 13))

/*
 * Clock disable macros
 */

#define GPIOx_PCLK_DI(SHIFT)    (RCC->AHB1ENR &= ~(1 << SHIFT))

#define GPIOA_PCLK_DI()         (GPIOx_PCLK_DI(0))
#define GPIOB_PCLK_DI()         (GPIOx_PCLK_DI(1))
#define GPIOC_PCLK_DI()         (GPIOx_PCLK_DI(2))
#define GPIOD_PCLK_DI()         (GPIOx_PCLK_DI(3))
#define GPIOE_PCLK_DI()         (GPIOx_PCLK_DI(4))
#define GPIOF_PCLK_DI()         (GPIOx_PCLK_DI(5))
#define GPIOG_PCLK_DI()         (GPIOx_PCLK_DI(6))
#define GPIOH_PCLK_DI()         (GPIOx_PCLK_DI(7))
#define SYSCFG_PCLK_DI()        (RCC->APB2 &= ~(1 << 14))
#define SPI1_PCLK_DI()          (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()          (RCC->APB2ENR &= ~(1 << 13))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOx_REG_RESET(SHIFT)  do { RCC->AHB1RSTR |= (1 << SHIFT); RCC->AHB1RSTR &= ~(1 << SHIFT); } while(0)

#define GPIOA_REG_RESET()       GPIOx_REG_RESET(0)
#define GPIOB_REG_RESET()       GPIOx_REG_RESET(1)
#define GPIOC_REG_RESET()       GPIOx_REG_RESET(2)
#define GPIOD_REG_RESET()       GPIOx_REG_RESET(3)
#define GPIOE_REG_RESET()       GPIOx_REG_RESET(4)
#define GPIOF_REG_RESET()       GPIOx_REG_RESET(5)
#define GPIOG_REG_RESET()       GPIOx_REG_RESET(6)
#define GPIOH_REG_RESET()       GPIOx_REG_RESET(7)

#define IRQ_NO_EXTI0            6
#define IRQ_NO_EXTI1            7
#define IRQ_NO_EXTI2            8
#define IRQ_NO_EXTI3            9
#define IRQ_NO_EXTI4            10
#define IRQ_NO_EXTI9_5          23
#define IRQ_NO_EXTI15_10        40


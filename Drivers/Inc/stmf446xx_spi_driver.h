#pragma once

#include <stddef.h>
#include "stmf446xx.h"

typedef struct {
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SclkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;
} SPI_Config_t;

typedef struct {
    SPI_RegDef_t *pSPIx;
    SPI_Config_t SPIConfig;
} SPI_Handle_t;

#define SPI_DEVICE_MODE_SLAVE       0
#define SPI_DEVICE_MODE_MASTER      1

#define SPI_BUS_CONFIG_FULL_DUPLEX  0
#define SPI_BUS_CONFIG_HALF_DUPLEX  1
#define SPI_BUS_CONFIG_SIMPLEX_TX   2
#define SPI_BUS_CONFIG_SIMPLEX_RX   3

#define SPI_SCLK_SPEED_DIV_2        0
#define SPI_SCLK_SPEED_DIV_4        1
#define SPI_SCLK_SPEED_DIV_8        2
#define SPI_SCLK_SPEED_DIV_16       3
#define SPI_SCLK_SPEED_DIV_32       4
#define SPI_SCLK_SPEED_DIV_64       5
#define SPI_SCLK_SPEED_DIV_128      6
#define SPI_SCLK_SPEED_DIV_256      7

#define SPI_DFF_8                   0
#define SPI_DFF_16                  1

#define SPI_CPOL_LOW                0
#define SPI_CPOL_HIGH               1

#define SPI_CPHA_FIRST              0
#define SPI_CPHA_SECOND             1

#define SPI_SSM_DISABLED            0
#define SPI_SSM_ENABLED             1

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t enable);

void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t* pTxBuffer, size_t len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t* pRxBuffer, size_t len);

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t enable);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);

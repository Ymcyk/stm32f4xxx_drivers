#include "stmf446xx_spi_driver.h"

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t enable) {
    if (enable) {
        if (pSPIx == SPI1) {
            SPI1_PCLK_EN();
        } else if (pSPIx == SPI2) {
            SPI2_PCLK_EN();
        } else if (pSPIx == SPI3) {
            SPI3_PCLK_EN();
        } else if (pSPIx == SPI4) {
            SPI4_PCLK_EN();
        }
    } else {
        if (pSPIx == SPI1) {
            SPI1_PCLK_DI();
        } else if (pSPIx == SPI2) {
            SPI2_PCLK_DI();
        } else if (pSPIx == SPI3) {
            SPI3_PCLK_DI();
        } else if (pSPIx == SPI4) {
            SPI4_PCLK_DI();
        }
    }
}

void SPI_Init(SPI_Handle_t *pSPIHandle) {

}

void SPI_DeInit(SPI_RegDef_t *pSPIx) {

}

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t* pTxBuffer, size_t len) {

}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t* pRxBuffer, size_t len) {

}

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t enable) {

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority) {

}

void SPI_IRQHandling(SPI_Handle_t *pSPIHandle) {

}

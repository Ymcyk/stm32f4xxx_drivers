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
    const SPI_Config_t * const SPIConfig = &(pSPIHandle->SPIConfig);

    uint32_t tempreg = 0;

    // 1. Configure device mode
    tempreg |= ((SPIConfig->SPI_DeviceMode & 0x01) << SPI_CR1_MSTR);

    // 2. Configure bus
    switch (SPIConfig->SPI_BusConfig) {
    case SPI_BUS_CONFIG_FULL_DUPLEX: {
        // jako że tempreg jest na zero to nie trzeba tego ustawiać
        tempreg &= ~(1 << SPI_CR1_BIDIMODE);
        break;
    }
    case SPI_BUS_CONFIG_HALF_DUPLEX: {
        // tu nie trzeba ustawiać czy będzie receiver, czy sender
        // w Half-duplex takie rzeczy są robione przez zdaje się
        // wysłanie odpowiednich rzeczy w wiadomości. Do tego jeszcze dojdę
        tempreg |= (1 << SPI_CR1_BIDIMODE);
        break;
    }
    case SPI_BUS_CONFIG_SIMPLEX_TX: {
        tempreg &= ~(1 << SPI_CR1_BIDIMODE);
        break;
    }
    case SPI_BUS_CONFIG_SIMPLEX_RX: {
        tempreg &= ~(1 << SPI_CR1_BIDIMODE);
        tempreg |= (1 << SPI_CR1_RXONLY);
        break;
    }
    default:
        break;
    }

    // 3. Configure SCLK
    tempreg |= (SPIConfig->SPI_SclkSpeed << SPI_CR1_BR);

    // 4. Configure DFF
    tempreg |= (SPIConfig->SPI_DFF << SPI_CR1_DFF);

    // 5. Configure CPOL
    tempreg |= (SPIConfig->SPI_CPOL << SPI_CR1_CPOL);

    // 6. Configure CPHA
    tempreg |= (SPIConfig->SPI_CPHA << SPI_CR1_CPHA);

    // 7. Configure SSM
//    tempreg |= (SPIConfig->SPI_SSM << 9);

    pSPIHandle->pSPIx->SPI_CR1 = tempreg;
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

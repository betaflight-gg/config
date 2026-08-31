/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/*
 * GETFUN F722 V3 custom target.
 *
 * The feature set is based on FLYWOOF722PROV2. Pin assignments are
 * reconstructed from the archived GETFUNF722V3 hardware baseline.
 */

#define FC_TARGET_MCU STM32F722

#define BOARD_NAME GETFUNF722V3
#define MANUFACTURER_ID GFUN

#define USE_ACC
#define USE_BARO
#define USE_FLASH
#define USE_GYRO

#define USE_ACC_SPI_ICM42688P
#define USE_BARO_DPS310
#define USE_FLASH_W25Q128FV
#define USE_GYRO_SPI_ICM42688P
#define USE_MAX7456

/* GPIO */
#define BEEPER_PIN PB0
#define BEEPER_INVERTED

#define LED0_PIN PC15
#define LED1_PIN PC14
#define LED_STRIP_PIN PB1

#define PINIO1_PIN PC4
#define PINIO2_PIN PB2

/* Motors */
#define MOTOR1_PIN PA15
#define MOTOR2_PIN PA10
#define MOTOR3_PIN PA9
#define MOTOR4_PIN PA8
#define MOTOR5_PIN PC9
#define MOTOR6_PIN PC8
#define MOTOR7_PIN PB11
#define MOTOR8_PIN PB10

/* UARTs */
#define UART1_TX_PIN PB6
#define UART1_RX_PIN PB7
#define UART2_TX_PIN PA2
#define UART2_RX_PIN PA3
#define UART3_TX_PIN PC10
#define UART3_RX_PIN PC11
#define UART4_TX_PIN PA0
#define UART4_RX_PIN PA1
#define UART5_TX_PIN PC12
#define UART5_RX_PIN PD2
#define UART6_TX_PIN PC6
#define UART6_RX_PIN PC7

/* I2C1: DPS310 and optional external magnetometer */
#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9

/* SPI1: ICM42688P */
#define SPI1_SCK_PIN PA5
#define SPI1_SDI_PIN PA6
#define SPI1_SDO_PIN PA7
#define GYRO_1_CS_PIN PA4

/* SPI2: MAX7456 */
#define SPI2_SCK_PIN PB13
#define SPI2_SDI_PIN PB14
#define SPI2_SDO_PIN PB15
#define MAX7456_SPI_CS_PIN PB12

/* SPI3: W25Q128FV */
#define SPI3_SCK_PIN PB3
#define SPI3_SDI_PIN PB4
#define SPI3_SDO_PIN PB5
#define FLASH_CS_PIN PC13

/* ADC3 */
#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PC1
#define ADC_RSSI_PIN PC2

/*
 * Timer occurrences select the archived hardware mappings:
 * PA15 TIM2_CH1, PA10 TIM1_CH3, PA9 TIM1_CH2, PA8 TIM1_CH1,
 * PC9 TIM8_CH4, PC8 TIM8_CH3, PB11 TIM2_CH4, PB10 TIM2_CH3,
 * and PB1 TIM3_CH4 for the LED strip.
 */
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN,     1, 0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN,     1, 0) \
    TIMER_PIN_MAP(2, MOTOR3_PIN,     1, 0) \
    TIMER_PIN_MAP(3, MOTOR4_PIN,     1, 0) \
    TIMER_PIN_MAP(4, MOTOR5_PIN,     2, 0) \
    TIMER_PIN_MAP(5, MOTOR6_PIN,     2, 0) \
    TIMER_PIN_MAP(6, MOTOR7_PIN,     1, 0) \
    TIMER_PIN_MAP(7, MOTOR8_PIN,     1, 0) \
    TIMER_PIN_MAP(8, LED_STRIP_PIN,  2, 0)

#define ADC3_DMA_OPT 0

#define MAG_I2C_INSTANCE I2CDEV_1
#define BARO_I2C_INSTANCE I2CDEV_1
#define ADC_INSTANCE ADC3

#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE SPI3
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW90_DEG

/* The original target did not define an ICM42688P EXTI/DRDY pin. */

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 100
#define DEFAULT_VOLTAGE_METER_SCALE 110
#define DEFAULT_PID_PROCESS_DENOM 4

#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define SERIALRX_UART SERIAL_PORT_USART2
#define SERIALRX_PROVIDER SERIALRX_CRSF

#define PINIO1_BOX 40
#define PINIO2_BOX 41

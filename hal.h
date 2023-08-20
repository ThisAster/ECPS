#include <stdint.h>

#ifndef HAL_H

#define PERIPH_BASE 0x40000000UL
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define __IO volatile


/**
 * GPIO Bit SET and Bit RESET enumeration
 */


typedef enum {
	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
} GPIO_PinState;

typedef enum {
	HAL_ERROR = 0,
	HAL_OK
} HAL_StatusTypeDef;

typedef struct {
	__IO uint32_t CRL;
	__IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
} GPIO_TypeDef;

/* !< AHB1 peripherals > */
#define GPIOA (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE (AHB1PERIPH_BASE + 0x1000UL)

#define GPIO_PIN_0     (0x0001)    /* Pin 0 is selected  */
#define GPIO_PIN_1     (0x0002)    /* Pin 1 is selected  */
#define GPIO_PIN_2     (0x0004)    /* Pin 2 is selected  */
#define GPIO_PIN_3     (0x0008)    /* Pin 3 is selected  */
#define GPIO_PIN_4     (0x0010)    /* Pin 4 is selected  */
#define GPIO_PIN_5     (0x0020)    /* Pin 5 is selected  */
#define GPIO_PIN_6     (0x0040)    /* Pin 6 is selected  */
#define GPIO_PIN_7     (0x0080)    /* Pin 7 is selected  */
#define GPIO_PIN_8     (0x0100)    /* Pin 8 is selected  */
#define GPIO_PIN_9     (0x0200)    /* Pin 9 is selected  */
#define GPIO_PIN_10    (0x0400)    /* Pin 10 is selected */
#define GPIO_PIN_11    (0x0800)    /* Pin 11 is selected */
#define GPIO_PIN_12    (0x1000)    /* Pin 12 is selected */
#define GPIO_PIN_13    (0x2000)    /* Pin 13 is selected */
#define GPIO_PIN_14    (0x4000)    /* Pin 14 is selected */
#define GPIO_PIN_15    (0x8000)    /* Pin 15 is selected */

#define TIM6_ARR    (0x1) /* регистр, хранящий значение перезагрузки */
#define TIM6_DIER    (0x1) /* регистр разрешения прерывания */
#define TIM_DIER_UIE    (0x1) /* регистр разрешения прерывания обновления */
#define TIM6_PSC    (0x1) /* регистр делителя тактового сигнала */
#define TIM6_CR1    (0x1) /* регистр управления */
#define TIM_CR1_CEN    (0x1) /* регистр управления (счетчик таймера вверх включен)*/
#define TIM6_CNT (0x1) /* счетный регистр таймера */
//6


//7
#define TIM7_ARR    (0x1) /* регистр, хранящий значение перезагрузки */
#define TIM7_DIER    (0x1) /* регистр разрешения прерывания */
#define TIM7_PSC    (0x1) /* регистр делителя тактового сигнала */
#define TIM7_CR1    (0x1) /* регистр управления */
#define TIM7_CNT (0x1) /* счетный регистр таймера */


void HAL_GPIO_TogglePin(unsigned int gpio_port, unsigned int pin);

GPIO_PinState HAL_GPIO_ReadPin(unsigned int gpio_port, unsigned int pin);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

void HAL_GPIO_WritePin(unsigned int gpio_port, unsigned int pin, GPIO_PinState pin_state);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

void HAL_Delay(unsigned int delay_ms);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);


/* ф-ии чтения/записи регистров */
unsigned int READ_REG(unsigned int reg_address);
unsigned int WRITE_REG(unsigned int reg_address, unsigned int);

/* ф-ии регистрации обработчиков прерываний от таймеров 
*/

/* аргумент ф-ии: ф-ия, которая является обработчиком и
она будет появляться при возникновении прерывания
*/
void registerTIM6_IRQHandler(void(*irqHandler)(/* ф-ия, которая является обрабочтиком и будет появляться при возниконовении прерывания*/));
void registerTIM7_IRQHandler(void(*irqHandler)());

/* ф-ии разрешения и запрещения прерывания*/
void __enable_irq();
void __disable_irq();

HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif

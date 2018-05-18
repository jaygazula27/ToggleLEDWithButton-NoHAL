#include "stm32f4xx.h"
#include "user_button.h"
#include "core_cm4.h"

static void enable_user_btn_clock(void);
static void configure_user_btn_interrupt(void);

void configure_user_button(void) {
    enable_user_btn_clock();
    configure_user_btn_interrupt();
    NVIC_EnableIRQ(EXTI0_IRQn);
}

void enable_user_btn_clock(void) {
    RCC_TypeDef *rcc = RCC;
    rcc->AHB1ENR |= (1 << 0);
}

void configure_user_btn_interrupt(void) {
    EXTI_TypeDef *exti = EXTI;
    exti->IMR |= (1 << 0);
    exti->RTSR |= (1 << 0);
    exti->FTSR |= (1 << 0);
}

int is_user_button_rising(void) {
    GPIO_TypeDef *gpio = GPIOA;
    return gpio->IDR & 1; // or (gpio->IDR >> 0) & (1 << 0)
}

#include "stm32f4xx.h"
#include "led.h"
#include "user_button.h"

static void clear_exti0_pending_register(void);

int main(void) {
    // Enable the clock for the LED GPIOs (port D)
    led_clock_init();

    // Enable the clock for the user button. And configure an interrupt on the EXTI0 line.
    configure_user_button();

    led_init(LED_GREEN);
    led_init(LED_ORANGE);
    led_init(LED_RED);
    led_init(LED_BLUE);

    while(1);
	return 0;
}

void EXTI0_IRQHandler(void) {
    if (is_user_button_rising()) {
        led_turn_on(LED_GREEN);
        led_turn_on(LED_ORANGE);
        led_turn_on(LED_RED);
        led_turn_on(LED_BLUE);
    } else {
        led_turn_off(LED_GREEN);
        led_turn_off(LED_ORANGE);
        led_turn_off(LED_RED);
        led_turn_off(LED_BLUE);
    }
    clear_exti0_pending_register();
}

void clear_exti0_pending_register(void) {
    EXTI_TypeDef *exti = EXTI;
    exti->PR |= (1 << 0);
}

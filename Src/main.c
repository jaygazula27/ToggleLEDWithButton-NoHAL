#include "stm32f4xx.h"
#include "led.h"

int main(void) {
    led_clock_init(); // Enable the clock for the LED GPIO (port D)

    led_init(LED_GREEN);
    led_init(LED_ORANGE);
    led_init(LED_RED);
    led_init(LED_BLUE);

    while(1) {
        led_turn_on(LED_GREEN);
        led_turn_on(LED_ORANGE);
        led_turn_on(LED_RED);
        led_turn_on(LED_BLUE);

        for(int i = 0; i < 350000; i++);

        led_turn_off(LED_GREEN);
        led_turn_off(LED_ORANGE);
        led_turn_off(LED_RED);
        led_turn_off(LED_BLUE);

        for(int i = 0; i < 350000; i++);
    }

	return 0;
}

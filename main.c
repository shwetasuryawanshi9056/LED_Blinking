//main.c

#include "functions.h"
#include "delay.h"

int main(void)
{
gpio_init();
uart0_init();
eint2_init();

while(1)
{
led_on();
delay_us(500);
led_off();
delay_us(500);
}
}

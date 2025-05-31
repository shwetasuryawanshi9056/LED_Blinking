//functions.c

#include <LPC21xx.H>
#include "functions.h"

#define LED_PIN 10
#define SW_PIN 15

void gpio_init(void)
{
	IODIR0 |= (1<<LED_PIN);   //output
	IODIR0 &= ~(1<<SW_PIN);   //input
}

void led_on(void)
{
	IOSET0 = (1<< LED_PIN);
}

void led_off(void)
{
	IOCLR0 = (1 << LED_PIN);
}

void uart0_init(void)
{
	PINSEL0 |= 0X00000005;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0X03;
}

void uart0_send_string( const char* str)
{
	while(*str)
	{
		while (!(U0LSR & 0x20));
		U0THR = *str++;
	}
}

void eint2_init(void)
{
	PINSEL0 |= (1UL << 31);
	EXTINT = (1<<2);
	EXTMODE = (1<<2);
	EXTPOLAR = (1<<2);
	
	VICVectAddr2 = (unsigned long)eint2_isr;
	VICVectCntl2 = 0x20 | 16;
	VICIntEnable = (1<<16);
}

__irq void eint2_isr(void)
{
	uart0_send_string("Button 51 Pressed\r\n");
	EXTINT = (1<<2);
	VICVectAddr = 0;
}

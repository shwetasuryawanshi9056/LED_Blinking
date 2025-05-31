LPC2129_Button_LED_UART

This project demonstrates basic embedded programming on the LPC2129 microcontroller using GPIO, external interrupts, and UART.

Features
LED Blinking: An LED connected to P0.10 blinks every 500 microseconds.

Button Interrupt: A push button connected to P0.15 (pulled-down) triggers an external interrupt.

UART Output: On button press, sends "Button 51 Pressed" via UART0 at 9600 baud.

Assumptions
Clock: 15 MHz (default)

UART0 is used (TX: P0.0, RX: P0.1)

LED: Connected to P0.10

Button: Connected to P0.15 (falling edge interrupt)

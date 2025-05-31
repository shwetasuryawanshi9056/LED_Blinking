void gpio_init(void);
void led_on(void);
void led_off(void);

void uart0_init(void);
void uart0_send_string(const char* str);

void eint2_init(void);
void eint2_isr(void) __irq;

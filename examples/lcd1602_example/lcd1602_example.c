/*
 * lcd1602_example.c
 *
 * Created: 12/22/2023 9:32:17 PM
 * Author : minhhchienn
 */
#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdio.h>
#include "lcd1602.h"

int main(void)
{
	DDRC = 0xff;
	DDRD = 0xff;
	lcd_init();
	
	char buffer[16];
	snprintf(buffer, 16, "Hello World!");
	lcd_send_string(buffer);
	
	while(1);
    return 0;
}


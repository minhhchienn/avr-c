
/*
 * lcd1602.c
 *
 * Created: 12/22/2023 7:27:05 PM
 *  Author: minhhchienn
 */ 

#include "lcd1602.h"
#include <stdint.h>
#include <util/delay.h>

//Instruction set
#define LCD_CLEAR			0x01			//Clear screen
#define LCD_HOME			0x02			//Go to first if line one
#define LCD_SHIFT_LEFT			0x04			//Left-shift the cursor after writing a character
#define LCD_SHIFT_RIGHT			0x06			//Right-shift the cursor after writing a character
#define LCD_DISPLAY_OFF			0x08			//Turn off the display
#define LCD_DISPLAY_ON			0x0C			//Turn on the display

//DRAM
#define LCD_LINE_ONE			0x80			//First position of line one
#define LCD_LINE_TWO			0xC0			//First position of line two

void lcd_send_command(uint8_t command){
	LCD_DATA_PORT = command;
	LCD_CTRL_PORT &= ~(1 << LCD_RS);			//Set RS = 0 (command)
	LCD_CTRL_PORT &= ~(1 << LCD_RW);			//Set RS = 0 (write)
	LCD_CTRL_PORT |= (1 << LCD_E);				//Pull up enable
	_delay_us(1);						//Delay at least 450ns
	LCD_CTRL_PORT &= ~(1 << LCD_E);				//Pull down enable
	_delay_ms(1);
}

void lcd_send_data(uint8_t data){
	LCD_DATA_PORT = data;
	LCD_CTRL_PORT |= 1 << LCD_RS;				//Set RS = 1 (data)
	LCD_CTRL_PORT &= ~(1 << LCD_RW);			//Set RS = 0 (write)
	LCD_CTRL_PORT |= (1 << LCD_E);				//Pull up enable
	_delay_us(1);						//Delay at least 450ns
	LCD_CTRL_PORT &= ~(1 << LCD_E);				//Pull down enable
	_delay_ms(1);
}

void lcd_init(){
	_delay_ms(15);						//Delay at least 15ms
	lcd_send_command(LCD_HOME);
	lcd_send_command(0x38);					//8 bits mode, 2 line, 5x10 pixels per character
	lcd_send_command(LCD_DISPLAY_ON);
	lcd_send_command(LCD_SHIFT_LEFT);
	lcd_send_command(LCD_CLEAR);
	_delay_ms(2);
}

void lcd_send_string(const char* str){
	while(*str){
		lcd_send_data(*str++);
	}
}

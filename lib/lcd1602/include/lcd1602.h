/*
 * lcd1602.h
 *
 * Created: 12/22/2023 7:26:54 PM
 *  Author: minhhchienn
 */ 

#ifndef _LCD_1602_
#define _LCD_1602_
#pragma once

#include <avr/io.h>

#ifndef LCD_CTRL_PORT
#define LCD_CTRL_PORT PORTC
#endif

#ifndef LCD_RS
#define LCD_RS PC0
#endif

#ifndef LCD_RW
#define LCD_RW PC1
#endif

#ifndef LCD_E
#define LCD_E PC2
#endif

#ifndef LCD_DATA_PORT
#define LCD_DATA_PORT PORTD
#endif

//Initialize lcd
void lcd_init();

//Clear lcd screen
void lcd_clear();

//Set cursor to first position
void lcd_home();

//Write a string to lcd
void lcd_send_string(const char* str);

//Write a int number to lcd
void lcd_send_int(int n);

//Set cursor position
 void lcd_set_cursor(int row, int col);

#endif
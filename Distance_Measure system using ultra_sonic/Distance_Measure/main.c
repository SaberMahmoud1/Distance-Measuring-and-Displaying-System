/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.c
 *
 * Description: Source file for the AVR ICU driver
 *
 * Author: Saber Mahmoud
 *
 *******************************************************************************/
#include"ultrasonic.h"
#include"gpio.h"
#include <avr/io.h>
#include<util/delay.h>
void main(void)
{
	LCD_init();			/*start LCD*/
	Ultrasonic_init();		/* start the ultrasonic sensor*/
	SREG|=(1<<7);			/*enable global interrupt*/
	LCD_displayString("Distance=     cm");
	uint16 distance;
	while(TRUE)
	{
		LCD_moveCursor(0, 10);		/*move the cursor to row 0 column 10*/
		LCD_intgerToString(Ultrasonic_readDistance());
		LCD_displayCharacter(' ');

	}
}

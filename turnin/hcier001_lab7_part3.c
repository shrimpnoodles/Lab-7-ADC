/*	Author: Hannah Cierlak
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab 7 Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 * 	submission link: https://drive.google.com/file/d/1pso79xI7jc5EidopVWo1Zm5pjyiZ5LPU/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADEN: SETTING THIS BIT ENABLES ANALOG TO DIGITAL CONVERSION
	//ADSC: SETTING THIS BIT STARTS THE FIRST CONVERSION
	//ADATE: SETTING THIS BIT ENABLES AUTO TRIGGERING
	//	SINCE WE ARE IN FREE RUNNING MODE A NEW CONVERSION
	//	WILL TRIGGER WHENEVER THE PREVIOUS CONVERSION COMPLETES
}


int main(void) {
    /* Insert DDR and PORT initializations */
//	DDRA =0X00; PORTA = 0XFF;
	DDRB = 0XFF; PORTB = 0X00;
	DDRD = 0XFF; PORTD = 0X00;

	ADC_init();
	unsigned char max= 46;
	unsigned short x = ADC;
    /* Insert your solution below */
    while (1) {
	    
	    x = ADC;
	  
	   /* PORTD = (char)(x>>8);
	    PORTB= (char)x; */ 
	  
	    if(x >=(max/2)){
		    PORTB = 0x01;
		   }
	    else{
		    PORTB= 0X00;
		  }
    }
    return 1;
}

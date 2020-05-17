/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);

}

int main(void) {
    /* Insert DDR and PORT initializations */

    /* Insert your solution below */
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	//input short x = ADC
	ADC_init();
	unsigned short x = 0;
	unsigned char out = 0;
    while (1) {
	x = ADC;
	out = 0x00;
	/*
	if(x >= 0x200){
	out = 0x02;
	x = x - 0x200;
	}
	if(x >= 0x100){
	out = (out | 0x01);
	x = x - 0x100;
	}
	PORTD = out;
	
	out = x;	
	PORTB = out;
	*/
	
	if(x >= 512){
	PORTB = 0x01;
	}
	if(x < 512){
	PORTB = 0x00;
	}
	
	/*if(x < 64){
	PORTB = 0x01;
	}
	else if(x < 128){
	PORTB = 0x02;

        }
	else if(x < 192){
	PORTB = 0x04;

        }
	else if(x < 256){
	PORTB = 0x08;

        }
	else if(x < 320){
	PORTB = 0x10;

        }
	else if(x < 384){
	PORTB = 0x20;

        }
	else if(x < 448){
	PORTB = 0x40;

        }
	else if(x <= 512){
	PORTB = 0x80;

        }
	*/


    }
    return 1;
}

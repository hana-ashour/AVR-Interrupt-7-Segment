/*
 * main.c
 *
 *  Created on: Jan 16, 2022
 *      Author: hanaashour
 */
#include "../include/LIB/types.h"
#include "../include/LIB/bit.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/MCAL/EXTINT/EXTINT_interface.h"
#include "../include/MCAL/EXTINT/EXTINT_private.h"
#include "../include/MCAL/EXTINT/EXTINT_configuration.h"

#include "../include/MCAL/GPI/GPI_interface.h"
#include "../include/MCAL/GPI/GPI_private.h"
#include "../include/MCAL/GPI/GPI_configuration.h"

#include "../include/HAL/SEG_interface.h"
#include "../include/HAL/SEG_private.h"
#include "../include/HAL/SEG_configuration.h"

void TOGGLED(void)
{
	static u8 flag = 1;
	H7Seg_voidDispalyNumber(flag);
	flag++;
	if(flag >10)
	{
		flag = 1;
	}

}

void main()
{
	GPI_voidInit();
	H7Seg_voidInit();
	MDIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_INPUT_PULLUP);//to make the pin input
	MEXTINT_voidEXTINT_ENABLE(EXTINT_u8_EXTINT0, EXTINT_u8_FALLING_EDGE);
	MEXTINT_voidSetCallBack(&TOGGLED, EXTINT_u8_EXTINT0);

	while(1){

	}
}


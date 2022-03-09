/*
 * GPI_program.c
 *
 *  Created on: Jan 11, 2022
 *      Author: hanaashour
 */

#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/MCAL/GPI/GPI_interface.h"
#include "../include/MCAL/GPI/GPI_private.h"
#include "../include/MCAL/GPI/GPI_configuration.h"


void GPI_voidInit(void)
{
	if (GPI_u8_MODE ==GPI_u8_ENABLE)
	{
		SET(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
	}

	else
	{
		CLR(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
	}

}
void GPI_voidEnable(void)
{
	SET(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}
void GPI_voidDisable(void)
{
	CLR(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}

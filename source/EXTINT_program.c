/*
 * EXTINT_program.c
 *
 *  Created on: Jan 15, 2022
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

static void (*pf[3]) (void) = {NULL,NULL,NULL};

void MEXTINT_voidEXTINT_ENABLE(u8 copy_u8EXTINT_Num, u8 copy_u8EXTINT_sense)
{
	if(copy_u8EXTINT_Num<0||copy_u8EXTINT_Num>2||copy_u8EXTINT_sense<0||copy_u8EXTINT_sense>3)
	{
	}
	else if((copy_u8EXTINT_Num == EXTINT_u8_EXTINT2) && (copy_u8EXTINT_sense<2))
		{

		}
	else
	{
		switch(copy_u8EXTINT_Num)
		{
		case EXTINT_u8_EXTINT0:
			SET(EXTINT_u8_GICR,EXTINT_u8_EXTINT0_ENABLE_BIT);
			switch(copy_u8EXTINT_sense)
			{
			case EXTINT_u8_LOW_LEVEL:
				CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT0);
				CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT1);
				break;
			case EXTINT_u8_LOGICAL_MODE:
				SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT0);
				CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT1);
				break;
			case EXTINT_u8_FALLING_EDGE:
				CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT0);
				SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT1);
				break;
			case EXTINT_u8_RISING_EDGE:
				SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT0);
				SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT1);
				break;
			}
			break;
		case EXTINT_u8_EXTINT1:
			SET(EXTINT_u8_GICR,EXTINT_u8_EXTINT1_ENABLE_BIT);
			switch(copy_u8EXTINT_sense)
					{
					case EXTINT_u8_LOW_LEVEL:
						CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT2);
						CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT3);
						break;
					case EXTINT_u8_LOGICAL_MODE:
						SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT2);
						CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT3);
						break;
					case EXTINT_u8_FALLING_EDGE:
						CLR(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT2);
						SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT3);
						break;
					case EXTINT_u8_RISING_EDGE:
						SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT2);
						SET(EXTINT_u8_MCUCR,EXTINT_u8_MCUCR_BIT3);
						break;
					}
			break;
			case EXTINT_u8_EXTINT2:
					SET(EXTINT_u8_GICR,EXTINT_u8_EXTINT2_ENABLE_BIT);
					switch(copy_u8EXTINT_sense)
					{
					case EXTINT_u8_FALLING_EDGE:
						CLR(EXTINT_u8_MCUCSR,EXTINT_u8_MCUCSR_BIT6);
						break;
					case EXTINT_u8_RISING_EDGE:
						SET(EXTINT_u8_MCUCSR,EXTINT_u8_MCUCSR_BIT6);
						break;
					}
					break;
		}

	}
}

void MEXTINT_voidEXTINTDisable(u8 copy_u8EXTINT_Num)
{
	switch(copy_u8EXTINT_Num)
	{
	case EXTINT_u8_EXTINT0:
		CLR(EXTINT_u8_GICR,EXTINT_u8_EXTINT0_ENABLE_BIT);
		break;
	case EXTINT_u8_EXTINT1:
		CLR(EXTINT_u8_GICR,EXTINT_u8_EXTINT1_ENABLE_BIT);
		break;
	case EXTINT_u8_EXTINT2:
		CLR(EXTINT_u8_GICR,EXTINT_u8_EXTINT2_ENABLE_BIT);
		break;
	default: break;
	}

}
void MEXTINT_voidSetCallBack(void(*copy_PtrToFunction)(void),u8 copy_index)
{
	pf[copy_index] = copy_PtrToFunction;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(pf[EXTINT_u8_EXTINT0] != NULL)
	{
		pf[EXTINT_u8_EXTINT0]();
	}
}

void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(pf[EXTINT_u8_EXTINT1] != NULL)
		{
			pf[EXTINT_u8_EXTINT1]();
		}
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(pf[EXTINT_u8_EXTINT2] != NULL)
		{
			pf[EXTINT_u8_EXTINT2]();
		}
}




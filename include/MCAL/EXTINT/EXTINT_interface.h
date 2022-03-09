/*
 * EXTINT_interface.h
 *
 *  Created on: Jan 15, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_
#define INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_

#define EXTINT_u8_EXTINT0					0
#define EXTINT_u8_EXTINT1					1
#define EXTINT_u8_EXTINT2					2

#define EXTINT_u8_EXTINT0_ENABLE_BIT		6
#define EXTINT_u8_EXTINT1_ENABLE_BIT		7
#define EXTINT_u8_EXTINT2_ENABLE_BIT		5

#define EXTINT_u8_ENABLE					1
#define EXTINT_u8_DISABLE					0

#define EXTINT_u8_LOW_LEVEL					0
#define EXTINT_u8_LOGICAL_MODE				1
#define EXTINT_u8_FALLING_EDGE				2
#define EXTINT_u8_RISING_EDGE				3

#define NULL  								((void *) 0)

void MEXTINT_voidEXTINT_ENABLE(u8 copy_u8EXTINT_Num, u8 copy_u8EXTINT_sense);
void MEXTINT_voidEXTINTDisable(u8 copy_u8EXTINT_Num);
void MEXTINT_voidSetCallBack(void(*copy_PtrToFunction)(void),u8 copy_index);

#endif /* INCLUDE_MCAL_EXTINT_EXTINT_INTERFACE_H_ */

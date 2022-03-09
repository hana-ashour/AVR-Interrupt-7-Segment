/*
 * EXTINT_private.h
 *
 *  Created on: Jan 15, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_MCAL_EXTINT_EXTINT_PRIVATE_H_
#define INCLUDE_MCAL_EXTINT_EXTINT_PRIVATE_H_

#define EXTINT_u8_MCUCR						*((volatile u8 *)0x55)
#define EXTINT_u8_MCUCSR					*((volatile u8 *)0x54)
#define EXTINT_u8_GICR						*((volatile u8 *)0x5B)
#define EXTINT_u8_GIFR						*((volatile u8 *)0x5A)

#define EXTINT_u8_MCUCR_BIT0				0
#define EXTINT_u8_MCUCR_BIT1				1
#define EXTINT_u8_MCUCR_BIT2				2
#define EXTINT_u8_MCUCR_BIT3				3

#define EXTINT_u8_MCUCSR_BIT6				6

#endif /* INCLUDE_MCAL_EXTINT_EXTINT_PRIVATE_H_ */

/*
 * GPI_private.h
 *
 *  Created on: Jan 13, 2022
 *      Author: hanaashour
 */

#ifndef INCLUDE_MCAL_GPI_GPI_PRIVATE_H_
#define INCLUDE_MCAL_GPI_GPI_PRIVATE_H_

#define SREG	*((volatile u8 *)0x5f)

#define GPI_u8_ENABLE				1
#define GPI_u8_DISABLE				0

#define GPI_u8_INTERRUPT_ENABLE_BIT	7

#endif /* INCLUDE_MCAL_GPI_GPI_PRIVATE_H_ */

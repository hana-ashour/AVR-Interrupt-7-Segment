/*
 * SEG_program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: hanaashour
 */

#include <util/delay.h>
#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/HAL/SEG_interface.h"
#include "../include/HAL/SEG_private.h"
#include "../include/HAL/SEG_configuration.h"



void H7Seg_voidInit(void)
{
MDIO_voidSetPortDirection(segment_port, 0xff);

}
void H7Seg_voidDispalyNumber(u8 copy_u8Number)
{
	switch(copy_u8Number){
	case 1: MDIO_voidSetPortValue(segment_port,ZERO);break;
	case 2: MDIO_voidSetPortValue(segment_port, ONE);break;
	case 3: MDIO_voidSetPortValue(segment_port, TWO);break;
	case 4: MDIO_voidSetPortValue(segment_port, THREE);break;
	case 5: MDIO_voidSetPortValue(segment_port, FOUR);break;
	case 6: MDIO_voidSetPortValue(segment_port, FIVE);break;
	case 7: MDIO_voidSetPortValue(segment_port, SIX);break;
	case 8: MDIO_voidSetPortValue(segment_port, SEVEN);break;
	case 9: MDIO_voidSetPortValue(segment_port, EIGHT);break;
	case 10: MDIO_voidSetPortValue(segment_port, NINE);break;
	}

}


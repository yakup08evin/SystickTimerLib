/*
 * SysticLib.h
 *
 *  Created on: Nov 2, 2022
 *      Author: 90551
 */

#ifndef LIBRARY_SYSTICLIB_H_
#define LIBRARY_SYSTICLIB_H_

#include "main.h"


#define SysticTimerCount 6

typedef enum{
	bTrue = 0xFF,
	bFalse= 0x00,

}eBool_t;

typedef enum{
	eTimerId0,
	eTimerId1,
	eTimerId2,
	eTimerId3,
	eTimerId4,
	eTimerId5,

}eTimerId_t;

typedef struct{
	eBool_t  			active;
	volatile uint32_t 	setTime;
	volatile uint32_t 	time;
	eBool_t 			Loop;

}SysTickTimer_t;

SysTickTimer_t SysTimer[SysticTimerCount];

void sysTimerInit(void);
void sysTimerSet(eTimerId_t TimerId,uint32_t setTime,eBool_t Loop);
eBool_t sysTimerGetTime(eTimerId_t TimerId);



#endif /* LIBRARY_SYSTICLIB_H_ */

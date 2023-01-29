/*
 * SystickLib.c
 *
 *  Created on: Nov 2, 2022
 *      Author: 90551
 */


#include "main.h"
#include "SysticLib.h"

void sysTimerInit(void){
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void sysTimerSet(eTimerId_t TimerId,uint32_t setTime,eBool_t Loop){
	SysTimer[TimerId].active = bTrue;
	SysTimer[TimerId].setTime = setTime;
	SysTimer[TimerId].time = 0;
	SysTimer[TimerId].Loop = Loop;

}

eBool_t sysTimerGetTime(eTimerId_t TimerId){
	return  SysTimer[TimerId].time;
}

void sysTickISR(void){
	for(int i = 0;i < SysticTimerCount ; i++){
		if(SysTimer[i].active){
			if(SysTimer[i].time >= SysTimer[i].setTime){
				SysTimer[i].time = 0;
				if(!(SysTimer[i].Loop)){
					SysTimer[i].active = bFalse;
				}
			}
			else{
				SysTimer[i].time++;

			}
		}
	}

}
void SysTick_Handler(void)
{

	sysTickISR();
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}


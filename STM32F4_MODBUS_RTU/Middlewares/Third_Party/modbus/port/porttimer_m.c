/*
 * FreeModbus Libary: RT-Thread Port
 * Copyright (C) 2013 Armink <armink.ztl@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: porttimer_m.c,v 1.60 2013/08/13 15:07:05 Armink add Master Functions$
 */

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "mbconfig.h"

#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
/* ----------------------- Variables ----------------------------------------*/
extern TIM_HandleTypeDef htim7;
//static USHORT usT35TimeOut50us;
//static struct rt_timer timer;
uint16_t timeout = 0;
uint16_t downcounter = 0;

//static void prvvTIMERExpiredISR(void);
//static void timer_timeout_ind(void* parameter);

/* ----------------------- static functions ---------------------------------*/
//static void prvvTIMERExpiredISR(void);

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBMasterPortTimersInit(USHORT usTim1Timerout50us)
{
	  TIM_MasterConfigTypeDef sMasterConfig;

	  htim7.Instance = TIM7;
	  htim7.Init.Prescaler = (HAL_RCC_GetPCLK1Freq() / 1000000) - 1;
	  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim7.Init.Period = 50 - 1;

	  timeout = usTim1Timerout50us;

	  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
	  {
	    return FALSE;
	  }

	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
	  {
	    return FALSE;
	  }

	  return TRUE;
}

void vMBMasterPortTimersT35Enable()
{
	  /* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
	  downcounter = timeout;
	  HAL_TIM_Base_Start_IT(&htim7);
}

void vMBMasterPortTimersConvertDelayEnable()
{
//    rt_tick_t timer_tick = MB_MASTER_DELAY_MS_CONVERT * RT_TICK_PER_SECOND / 1000;
//
//    /* Set current timer mode, don't change it.*/
//    vMBMasterSetCurTimerMode(MB_TMODE_CONVERT_DELAY);
//
//    rt_timer_control(&timer, RT_TIMER_CTRL_SET_TIME, &timer_tick);
//
//    rt_timer_start(&timer);
}

void vMBMasterPortTimersRespondTimeoutEnable()
{
//    rt_tick_t timer_tick = MB_MASTER_TIMEOUT_MS_RESPOND * RT_TICK_PER_SECOND / 1000;
//
//    /* Set current timer mode, don't change it.*/
//    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
//
//    rt_timer_control(&timer, RT_TIMER_CTRL_SET_TIME, &timer_tick);
//
//    rt_timer_start(&timer);
}

void vMBMasterPortTimersDisable()
{
	  /* Disable any pending timers. */
	  HAL_TIM_Base_Stop_IT(&htim7);
}

//void prvvTIMERExpiredISR(void)
//{
//    (void) pxMBMasterPortCBTimerExpired();
//}
//
//static void timer_timeout_ind(void* parameter)
//{
//    prvvTIMERExpiredISR();
//}

#endif

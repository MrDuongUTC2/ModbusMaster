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
 * File: $Id: portserial_m.c,v 1.60 2013/08/13 15:07:05 Armink add Master Functions $
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "mbconfig.h"


#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
/* ----------------------- variables ---------------------------------*/
extern UART_HandleTypeDef huart2;
/* ----------------------- Defines ------------------------------------------*/
/* serial transmit event */

/* ----------------------- static functions ---------------------------------*/

/* ----------------------- Start implementation -----------------------------*/

void vMBMasterPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{
	  /* If xRXEnable enable serial receive interrupts. If xTxENable enable
	  * transmitter empty interrupts.
	  */

	  if (xRxEnable) {
	    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
	  } else {
	    __HAL_UART_DISABLE_IT(&huart2, UART_IT_RXNE);
	  }

	  if (xTxEnable) {
	    __HAL_UART_ENABLE_IT(&huart2, UART_IT_TXE);
	  } else {
	    __HAL_UART_DISABLE_IT(&huart2, UART_IT_TXE);
	  }
}

BOOL xMBMasterPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits,
        eMBParity eParity)
{
	  /*
	  Do nothing, Initialization is handled by MX_USART3_UART_Init()
	  Fixed port, baudrate, databit and parity
	  */
	  return TRUE;
}

BOOL xMBMasterPortSerialPutByte(CHAR ucByte)
{
	  /* Put a byte in the UARTs transmit buffer. This function is called
	  * by the protocol stack if pxMBFrameCBTransmitterEmpty( ) has been
	  * called. */
	  return (HAL_OK == HAL_UART_Transmit(&huart2, (uint8_t*)&ucByte, 1, 10));
}

BOOL xMBMasterPortSerialGetByte(CHAR * pucByte)
{
	  /* Return the byte in the UARTs receive buffer. This function is called
	  * by the protocol stack after pxMBFrameCBByteReceived( ) has been called.
	  */
	  *pucByte = (uint8_t)(huart2.Instance->DR & (uint8_t)0x00FF);
	  return TRUE;
}

#endif

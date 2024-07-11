 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Youssef Abuzeid
 *
 *******************************************************************************/
#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "common_macros.h"






/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	Five_Bit_Mode,Six_Bit_Mode,Seven_Bit_Mode,Eight_bit_Mode
}UART_BitData;

typedef enum{
	Parity_Disabled,Reserved,Parity_Even,Parity_Odd
}UART_Parity;

typedef enum{
	One_Bit,Two_Bits
}UART_StopBit;

typedef enum{
	BuadRate_2400=2400,BuadRate_4800=4800,
	BuadRate_9600=9600,BuadRate_14_4k=14400,
	BuadRate_19_2k=19200,BuadRate_28_8k=28800,
	BuadRate_38_4k=38400,BuadRate_57_6k=57600,
	BuadRate_76_8k=76800,BuadRate_115_2k=115200,
	BuadRate_230_4k=230400,BuadRate_250_0k=250000,
	BuadRate_500_0k=500000
}UART_BaudRate;

typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;
}UART_ConfigType;





/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */

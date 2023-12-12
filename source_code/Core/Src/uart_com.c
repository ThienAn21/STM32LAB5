/*
 * uart_com.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ASUS TUF GAMING
 */
#include "uart_com.h"

#define INIT 2
#define waiting_RST_state 3
#define waiting_OK_state 4


int Uart_Com_State = INIT;
void uart_communiation_fsm (){
	switch (Uart_Com_State) {
	case INIT:
		Uart_Com_State = waiting_RST_state;
		break;
	case waiting_RST_state:
		/*
		if(timer2_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer2(500);
		}
		*/
		if(command_flag == RST){
			Uart_Com_State = waiting_OK_state;
			setTimer1(10);
			get_ADC_value();
		}
		break;
	case waiting_OK_state:
		if(timer1_flag == 1){
			transmit_ADC_value();
			setTimer1(3000);
		}
		if(command_flag == OK){
			Uart_Com_State = waiting_RST_state;
			//setTimer2(100);
		}
		break;
	default:
		break;
	}
}

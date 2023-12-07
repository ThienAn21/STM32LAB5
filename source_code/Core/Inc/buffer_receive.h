/*
 * buffer_receive.h
 *
 *  Created on: Nov 23, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_BUFFER_RECEIVE_H_
#define INC_BUFFER_RECEIVE_H_

#include "main.h"

#define MAX_BUFFER_SIZE 30

extern uint8_t temp ;
extern uint8_t buffer [ MAX_BUFFER_SIZE ];
extern uint8_t index_buffer ;
extern uint8_t buffer_flag ;

extern int transmit_flag ;



#endif /* INC_BUFFER_RECEIVE_H_ */

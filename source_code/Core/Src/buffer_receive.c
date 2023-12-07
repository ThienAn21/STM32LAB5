/*
 * buffer_receive.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ASUS TUF GAMING
 */
#include "buffer_receive.h"

uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer [ MAX_BUFFER_SIZE ];
uint8_t buffer_flag = 0;
int transmit_flag = 0;

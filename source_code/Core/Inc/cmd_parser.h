/*
 * cmd_parser.h
 *
 *  Created on: Nov 23, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_CMD_PARSER_H_
#define INC_CMD_PARSER_H_
#include "main.h"
#include "buffer_receive.h"

#define RST 1
#define OK 2

extern int command_flag;
extern int command_data;

void command_parser_fsm ();

#endif /* INC_CMD_PARSER_H_ */

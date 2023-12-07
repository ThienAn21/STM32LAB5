/*
 * cmd_parser.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ASUS TUF GAMING
 */
#include "cmd_parser.h"
#define waiting_RST_state 3
#define waiting_OK_state 4


int command_flag = OK;
int command_data = OK;
int command_parser_state = waiting_RST_state;
int check_command_id;
int check_command_RST(){
	check_command_id = index_buffer;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != '#')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != 'T')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != 'S')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != 'R')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != '!')	return 0;
	return 1;
}
int check_command_OK(){
	check_command_id = index_buffer;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != '#')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != 'K')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != 'O')	return 0;
	if((check_command_id - 1) < 0) check_command_id = MAX_BUFFER_SIZE - 1;
	else check_command_id--;
	if(buffer[check_command_id] != '!')	return 0;
	return 1;
}

void command_parser_fsm (){
	switch (command_parser_state) {
	case waiting_RST_state:
		command_flag = OK;
		if(check_command_RST()){
			command_parser_state = waiting_OK_state;
			command_flag = RST;
		}
		break;
	case waiting_OK_state:
		command_flag = RST;
		if(check_command_OK()){
			command_parser_state = waiting_RST_state;
			command_flag = OK;
		}
		break;
	default:
		break;
	}
}

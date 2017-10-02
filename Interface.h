#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "Dictionary.h"

struct IO
{
	char *add;
	char *find;
	char *del;
	char *exit;
};

int IO_command(char *command, struct Dictionary *);
void IO_command_delete(struct Dictionary *dict);
void IO_command_add(struct Dictionary *dict);
void IO_command_find(struct Dictionary *dict);
char *input_buffer(char *buffer);

#endif /* INTERFACE_H_ */

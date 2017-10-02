#include "Interface.h"
#include <stdlib.h>
#include <string.h>

int IO_command(struct IO *interf, char *command)
{
	memset(interf, NULL, sizeof(struct IO));
	if ((interf == NULL) || (command == NULL))
	{
		return -1;
	}
	if ( (strcmp(command, "add")) == 0 )
	{
		strcpy(interf->add, command);
	}
	if ((strcmp(command, "del")) == 0 )
	{
		strcpy(interf->del, command);
	}
	if ((strcmp(command, "find")) == 0 )
	{
		strcpy(interf->find, command);
	}
	if ( (strcmp(command, "exit")) == 0)
	{
		strcpy(interf->exit, command);
	}
	return 0;
}
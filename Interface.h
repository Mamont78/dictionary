#pragma once

struct IO
{
	char *add;
	char *find;
	char *del;
	char *exit;
};

int IO_command(struct IO *,char *);

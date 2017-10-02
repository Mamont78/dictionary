#include <stdio.h>
#include "Interface.h"
#include "Words.h"
//#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int tmp = 0, opt;
	char *command = NULL;
	char *path;
	struct Dictionary dict;
	memset(&dict, 0, sizeof(dict));
	/*while ((opt = getopt(argc, argv, "o")) != -1)// тут перепешу посмотри что с удаление у меня не так
	{
		if (opt == 'o')
		{
			if (!(add_input_dictionary(dict, optarg)));//загрузка из файла
			{
				printf("file not found");
			}

		}
	}
	*/
	while (tmp == 0)
	{
		printf("Dictionary 1.0\nwrite command\nadd-add word\ndelete-delete word \nfind-find word\nexit\n");
		command = input_buffer(command);
		tmp = IO_command(command, &dict);
	}
	/*
	add_output_dictionary(dict, path);//выгрузка в файл
	*/
	return 0;
}

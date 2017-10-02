#include "Interface.h"
#include "Dictionary.h"
#include "Common.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int IO_command(char *command, struct Dictionary *dict)
{
	if ((command == NULL))
	{
		return -1;
	}
	if (!(strcmp(command, "add")))
	{
		free(command);
		IO_command_add(dict);
		return 0;
	}
	if (!(strcmp(command, "delete")))
	{
		free(command);
		IO_command_delete(dict);
		return 0;
	}
	if (!(strcmp(command, "find")))
	{
		free(command);
		IO_command_find(dict);
		return 0;
	}
	if (!(strcmp(command, "exit\0")))
	{
		free(command);
		return -2;
	}
	return 0;
}


void IO_command_add(struct Dictionary *dict)//функция команды добавление слова
{
	struct Word word;
	memset(&word, 0, sizeof(word));
	char *buffer = NULL;
	int tmp = 0;
	while (tmp == 0)
	{
		printf("Write word:");
		buffer = input_buffer(buffer);
		if (control_lengths(buffer))//проверка длины слова
		{
			printf("\nword length error \n ");
		}
		else if (check_record(buffer))//проверка на спец символы
		{
			printf("\nerror in characters");
		}
		else tmp += 1;
	}
	normalization(buffer);//перевод из нижнего регистра в верхний
	word.word = strdup(buffer);
	free(buffer);
	printf("Write value:");
	buffer = input_buffer(buffer);
	word.value = strdup(buffer);
	free(buffer);
	add_dictionary(dict, &word, 0);//добавление слова в словарь
}


void IO_command_delete(struct Dictionary *dict)//функция команды удаление слова
{
	char *buffer = NULL;
	int tmp = 0;
	printf("Write word:");
	buffer = input_buffer(buffer);
	normalization(buffer);//перевод из нижнего регистра в верхний
	
	//tmp = delet_word(find_dictionary(dict, buffer), buffer, 0);//
	if (!tmp)
	{
		printf("word not found");
	}
	free(buffer);
}

void IO_command_find(struct Dictionary *dict)//функция команды поиска слова
{
	struct Word *wd;
	char *buffer = NULL;
	printf("Write word:");
	buffer = input_buffer(buffer);//считывание слова
	normalization(buffer);//перевод из нижнего регистра в верхний
	wd = find_word(find(find_dictionary(dict, buffer), buffer, 0), buffer, 0);//поиск слова
	if (wd == NULL)
	{
		printf("\nword not found");
	}
	else
	{
		printf("word :%s\nvalue:%s\n", wd->word, wd->value);
	}
}



char *input_buffer(char *buffer)//функция считывания слова
{
	int len = 5;
	char tmp;
	buffer = (char*)malloc(len);
	int i = 0;
	while ((tmp = getchar()) != '\n')
	{
		buffer[i] = tmp;
		i++;
		if (i + 1 >= len)
		{
			buffer = (char*)realloc(buffer, len + i);
			len += i;
		}
	}
	buffer[i] = '\0';
	return buffer;
}

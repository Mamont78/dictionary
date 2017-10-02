#include "Common.h"
#include "Words.h"
#include "Dictionary.h"
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int check_record(char *wd)
{
	char *special_characters = "!@""¹#;$%^:&?*()}{[]|/\\,.1234567890";
	int leng = strlen(special_characters);
	for (int counters = 0; counters < leng; ++counters)
	{
		if (strrchr(wd, special_characters[counters]))
		{
			return -1;
		}
	}
	return 0;
}

void normalization(char *wd)
{
	int counters = 0;
	while (wd[counters])
	{
		wd[counters] = toupper(wd[counters]);
		++counters;
	}
}

int control_lengths(char * wd)
{
	if (strlen(wd) <= 128)
	{
		return 0;
	}
	return -1;
}

int add_input_dictionary(struct Dictionary * dict, char * path)
{
	FILE *Diction;
	Diction = fopen(path, "r");
	if (Diction == NULL)
	{
		return -1;
	}
	fseek(Diction, 0, SEEK_END);
	long lSize = ftell(Diction);
	rewind(Diction);
	char * buffer = (char*)malloc(sizeof(char) * lSize);
	fread(buffer, 1, lSize, Diction);
	add_input_word(dict, buffer);
	fclose(Diction);
	if (Diction == NULL)
	{
		return -2;
	}
	return 0;
}

int add_input_word(struct Dictionary * dict, char * buffer)
{
	struct Word tmp_word;
	size_t tmp_line;
	memset(&tmp_word, 0, sizeof(tmp_word));
	tmp_line = get_line_buffer(buffer);
	while (tmp_line)
	{
		if (!strncmp("key=", buffer, 4))
		{
			tmp_word.word = strdup(buffer + 4);
		}
		else if (!strncmp("value=", buffer, 6))
		{
			tmp_word.value = strdup(buffer + 6);
			add_dictionary(dict, &tmp_word, 0);
			free(tmp_word.word);
			free(tmp_word.value);
		}
		buffer += tmp_line;
		tmp_line = get_line_buffer(buffer);
	}

	return 0;
}

size_t get_line_buffer(char *buffer)
{
	size_t line = 0;

	while (*(buffer + line) != '\n')
	{
		++line;
	}
	return 0;
}

int add_output_dictionary(struct Dictionary * dict, char *path)
{
	FILE *Diction;
	Diction = fopen(path, "w");
	if (Diction == NULL)
	{
		return -1;
	}
	dictionary_passage(dict, Diction);
	fclose(Diction);
	if (Diction == NULL)
	{
		return -2;
	}
	return 0;
}

int dictionary_passage(struct Dictionary *dict, FILE *Diction)
{
	if (dict->left_ptr != NULL)
	{
		dictionary_passage(dict->left_ptr, Diction);
	}
	if (dict->right_ptr != NULL)
	{
		dictionary_passage(dict->right_ptr, Diction);
	}
	if (dict->list)
	{
		list_words_passage(dict->list, Diction);
	}
	return 0;
}

struct List_words *list_words_passage(struct List_words *list, FILE *Diction)
{
	if (list != NULL)
	{
		fwrite("key=", 4, 1, Diction);
		fwrite(list->wd.word, strlen(list->wd.word), 1, Diction);
		fwrite("\n", 1, 1, Diction);
		fwrite("value=", 6, 1, Diction);
		fwrite(list->wd.value, strlen(list->wd.value), 1, Diction);
		fwrite("\n", 1, 1, Diction);
		return list_words_passage(list->next, Diction);
	}
	return NULL;
}


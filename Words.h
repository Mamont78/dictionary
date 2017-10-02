#pragma once

struct List_words *creat_word(struct Word const *);
int add_next_word(struct List_words **, struct Word const *);

struct Word	//слово
{
	char *word;
	char *value;
};

struct List_words                                   //список слов
{
	struct Word wd;
	struct List_words *next;
};


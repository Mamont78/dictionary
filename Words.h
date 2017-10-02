#pragma once


struct Word //слово
{
	char *word; 
	char *value;
};

struct List_words //список слов
{
	struct Word wd;
	struct List_words *next;
};

int add_word(struct List_words **, struct Word const *);
struct List_words *find(struct List_words *, char *, int );
int delet_word(struct List_words *, char *, int );
struct Word *find_word(struct List_words *, char *,int );

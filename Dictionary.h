#pragma once
#include "Words.h"

struct Dictionary                              //бинарное дерево разделяет на гласные согласные
{

	struct Dictionary *left_ptr;              //гласные
	struct Dictionary *right_ptr;             //согласнык
	struct List_words *list;                  //список слов
};

int add_Dictionary(struct Dictionary *, struct Word *, int );
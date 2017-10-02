#include "Words.h"
#include "Dictionary.h"
#include <stdlib.h>
#include <string.h>

struct List_words *creat_word( struct Word const *new_wd )
{
	struct List_words *word = (List_words*)malloc(sizeof(List_words));
	word->wd.word = new_wd->word;
	word->wd.value = new_wd->value;
	word->next = NULL;
	return word;
}

int add_next_word(struct List_words **list, struct Word const *new_wd)
{
	if (*list == NULL)
	{
		*list = creat_word(new_wd);
	}
	else (*list)->next = creat_word(new_wd);
	return 1;
}

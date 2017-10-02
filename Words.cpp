#include "Words.h"
#include "Dictionary.h"
#include <stdlib.h>
#include <string.h>

struct List_words *creat_word(struct Word const *);

struct List_words *creat_word(struct Word const *new_wd)
{
	if ( (new_wd->word == NULL) || (new_wd->value == NULL) )
	{
		return NULL;//он NULL возвращает
	}
	struct List_words *word = (List_words*)malloc(sizeof(List_words)); 
	memset(word, NULL, sizeof(struct Word));
	word->wd.word = strdup(new_wd->word);
	word->wd.value = strdup(new_wd->value);
	word->next = NULL;
	return word;
}

int add_word(struct List_words **list, struct Word const *new_wd) 
{
	if (*list == NULL)
	{
		*list = creat_word(new_wd);
		if (*list == NULL)
		{
			return -1;
		}
		return 0;
	}
	return add_word(&(*list)->next, new_wd);
}

struct Word *find_word( struct List_words *list, char *wd, int repeat ) 
{
	struct List_words *tmp_list = find( list, wd, repeat );
	if (tmp_list == NULL)
	{
		return NULL;
	}
	return &tmp_list->wd;
}

struct List_words *find(struct List_words *list, char *wd, int repeat)
{
	struct List_words *tmp;
	tmp = list;
	if ((wd == NULL) || (list == NULL) || (repeat < 0))
	{
		return NULL;
	}
	do
	{
		if (strcmp(tmp->wd.word, wd) == 0)
		{
			if (repeat == 0)
			{
				return tmp;
			}
			--repeat;
		}
		tmp = tmp->next;
	} while (tmp != NULL);
	return NULL;
}

int delet_word(struct List_words *list, char *wd, int repeat)
{
	struct List_words *list_tmp_head = list;
	struct List_words *list_tmp_tail = find(list, wd, 0);
	if ( (list_tmp_head == NULL) || (list_tmp_tail == NULL) )
	{
		return -1;
	}
	while (list_tmp_head->next != list_tmp_tail) // просматриваем список начиная с корня пока не найдем узел, предшествующий list_tmp_tail
	{
		list_tmp_head = list_tmp_head->next;
	}
	list_tmp_head->next = list_tmp_tail->next;
	free(list_tmp_tail);
	return 0;
}

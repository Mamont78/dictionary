#include "Words.h"
#include "Dictionary.h"
#include <stdlib.h>
#include <string.h>

struct List_words *creat_word(struct Word const *);

struct List_words *creat_word(struct Word const *new_wd)
{
	if ((new_wd->word == NULL) || (new_wd->value == NULL))
	{
		return NULL;
	}
	struct List_words *word = (struct List_words*)malloc(sizeof(struct List_words));
	if (word == NULL)
	{
		return NULL;
	}
	memset(word, 0, sizeof(*word));
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

struct Word *find_word(struct List_words *list, char *wd, int repeat)
{
	struct List_words *tmp_list = find(list, wd, repeat);
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

int delet_word(struct List_words *list, char *wd, int repeat)//()
{
	struct List_words *list_tmp_head = list;
	struct List_words *list_tmp_tail = find(list, wd, 0);
	if ((list_tmp_head == NULL) || (list_tmp_tail == NULL))
	{
		return -1;
	}
	if (list_tmp_head == list_tmp_tail)
	{
		free(list_tmp_tail->wd.word);
		free(list_tmp_tail->wd.value);
		free(list_tmp_tail);
		return 1;//return delete dictionary()
	}
	while (list_tmp_head->next != list_tmp_tail) // поиск по списку и удаление
	{
		list_tmp_head = list_tmp_head->next;
	}
	list_tmp_head->next = list_tmp_tail->next;
	free(list_tmp_tail->wd.word);
	free(list_tmp_tail->wd.value);
	free(list_tmp_tail);
	return 0;
}

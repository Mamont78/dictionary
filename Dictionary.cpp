#include "Dictionary.h"
#include "Words.h"
#include <stdlib.h>
#include <string.h>

static const char vowel[] = "AEIOU";
static const char consonant[] = "BCDFGHJKLMNPQRSTVWXYZ";

int add_dictionary(struct Dictionary *unit, struct Word *new_wd, int number)
{
	if ((unit == NULL) || (new_wd == NULL) || (number < 0))
	{
		return -1;
	}
	if (number >= strlen(new_wd->word))
	{
		return add_word(&unit->list, new_wd);
	}
	if (strrchr(vowel, new_wd->word[number]))
	{
		if (unit->left_ptr == NULL)
		{
			unit->left_ptr = (struct Dictionary*)malloc(sizeof(*unit));
			if (unit->left_ptr == NULL)
			{
				return -2;
			}
			memset(unit->left_ptr, 0, sizeof(struct Dictionary));
		}
		return add_dictionary(unit->left_ptr, new_wd, number + 1);
	}
	if (strrchr(consonant, new_wd->word[number]))
	{
		if (unit->right_ptr == NULL)
		{
			unit->right_ptr = (struct Dictionary*)malloc(sizeof(*unit));
			if (unit->right_ptr == NULL)
			{
				return -3;
			}
			memset(unit->right_ptr, 0, sizeof(struct Dictionary));
		}
		return add_dictionary(unit->right_ptr, new_wd, number + 1);
	}
	return -4;
}

struct List_words *find_dictionary(struct Dictionary * dict, char * wd)
{
	if ((wd == NULL) || (dict == NULL))
	{
		return NULL;
	}
	if (!(*wd))
	{
		return dict->list;
	}
	if (strrchr(vowel, *wd))
	{
		return find_dictionary(dict->left_ptr, wd + 1);
	}
	if (strrchr(consonant, *wd))
	{
		return find_dictionary(dict->right_ptr, wd + 1);
	}
	return NULL;
}

struct List_words *delete_dictionary(struct Dictionary *dict, char *wd)
{
	struct List_words *tmp_ptr;
	memset(&tmp_ptr, 0, sizeof(tmp_ptr));
	if ((wd == NULL) || (dict == NULL) || (!(*wd)))
	{
		return NULL;
	}
	if (strrchr(vowel, *wd))
	{
		tmp_ptr = delete_dictionary(dict->left_ptr, wd += 1);
		if ((dict->right_ptr == NULL) && (tmp_ptr == NULL) && (dict->list == NULL))
		{
			free(dict);
			return NULL;
		}
		return NULL;
	}
	if (strrchr(consonant, *wd))
	{
		tmp_ptr = delete_dictionary(dict->right_ptr, wd += 1);
		if ((dict->left_ptr == NULL) && (tmp_ptr == NULL) && (dict->list == NULL))
		{
			free(dict);
			return NULL;
		return NULL;
	}
}

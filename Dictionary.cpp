#include "Dictionary.h"
#include "Words.h"
#include <stdlib.h>
#include <string.h>

static const char vowel[] = "аоиеЄэыую€"; //проверка на гласные
static const char consonant[] = "бвгджзйклмнпрстфхцчшщ"; // проверка на согласные

int add_Dictionary( struct Dictionary *unit, struct Word *new_wd, int number ) //добавление слова
{
	if ( (unit == NULL) || (new_wd == NULL) || (number < 0) ) // проверка на путоту
	{
		return -1;
	}
	if ( number >= strlen(new_wd->word ) ) // конец рекурсии
	{
		return add_word( &unit->list ,new_wd );//добавление слова
	}
	if (strrchr(vowel, new_wd->word[number]))
	{
		if ( unit->left_ptr == NULL )
		{
			unit->left_ptr = (Dictionary*)malloc(sizeof(*unit));
			if ( unit->left_ptr == NULL )
			{
				return -2;
			}
			memset( unit->left_ptr, NULL, sizeof(Dictionary) );
		}
		return add_Dictionary( unit->left_ptr, new_wd, number + 1 );
	}
	if (strrchr( consonant, new_wd->word[number]) )
	{
		if  ( unit->right_ptr == NULL )
		{
			unit->right_ptr = (Dictionary*)malloc(sizeof(*unit));
			if ( unit->right_ptr == NULL )
			{
				return -3;
			}
			memset(unit->right_ptr, NULL, sizeof(Dictionary));
		}
		return add_Dictionary( unit->right_ptr, new_wd, number + 1 );
	}
	return -4;
}


struct List_words *find_dictionary(struct Dictionary * dict, char * wd)
{
	if ( ( wd == NULL ) || ( dict == NULL ) )
	{
			return NULL;
	}
	if ( !(*wd) )
	{
		return dict->list;
	}
	if (strrchr(vowel, *wd)) //гласные
	{
		return find_dictionary ( dict->left_ptr, wd + 1 );
	}
	if (strrchr(consonant, *wd)) //гласные
	{
		return find_dictionary(dict->right_ptr, wd + 1);
	}
	return NULL;
}

#include "Dictionary.h"
#include "Words.h"
#include <stdlib.h>
#include <string.h>

int add_Dictionary(struct Dictionary *unit, struct Word *new_wd, int number) //добавление слова
{
	static const char vowel[] = "аоиеЄэыую€"; //проверка на гласные
	static const char consonant[] = "бвгджзйклмнпрстфхцчшщ"; // проверка на согласные	
	if ((unit == NULL) || (new_wd == NULL) || (number < 0) ) // проверка на путоту
	{
		return -1;
	}
	if (number > strlen(new_wd->word )) // конец рекурсии 
	{
		return add_next_word( &unit->list ,new_wd );
	}
	if (strrchr(vowel, new_wd->word[number]))
	{
		if (unit->left_ptr == NULL)
		{
			unit->left_ptr = (Dictionary*)malloc(sizeof(*unit));
			memset(unit->left_ptr, NULL, sizeof(Dictionary));
			if (unit->left_ptr == NULL)
			{
				return -2;
			}
		}
		return add_Dictionary(unit->left_ptr, new_wd, number + 1);
}
	if (strrchr(consonant, new_wd->word[number]))
	{
		if (unit->right_ptr == NULL) 
		{
			unit->right_ptr = (Dictionary*)malloc(sizeof(*unit));// ок
			memset(unit->right_ptr, NULL, sizeof(Dictionary));
			if (unit->right_ptr == NULL)
			{
				return -3;
			}
		}
		return add_Dictionary(unit->right_ptr, new_wd, number + 1);;
	}
	return -4;
}

#include "Common.h"
#include "Words.h"
#include <string.h>
#include <ctype.h>
#include <locale.h>


int check_record( struct Word *wd )                  //проверка записи слова. это прийдеться переписать
{
	int counters = 0; //счетчик
	char *special_characters = "!@""№#;$%^:&?*()}{[]|/\\,.1234567890"; // символы недопустимые в слове
	for (counters; counters < strlen(special_characters); ++counters)//цикл для проверки  недопустимых символов в слове
	{
		if (strrchr(wd->word, special_characters[counters]))//проверка недопустимых символыв в слове
		{
			return -1;
		}
	}
	return 0;
}

void normalization( struct Word *wd ) //нормализация слова. Перевод с верхнего регистра в нижний
{
	int counters = 0;	//счетчик
	setlocale(LC_ALL, "Russian"); //языковой стандарт
	while (wd->word[counters]) //цикл для преобразовать заглавных букв в строчные
	{
		wd->word[counters] = tolower(wd->word[counters]);  // преобразовать текущий символ строки в строчный
		++counters;
	}
}

int control_lengths(struct Word * wd) //функция проверка длины слова
{
	if (strlen(wd->word) <= 128) //проверка длины
	{
		return 0;
	}
	return -2;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD "Hello&"

struct Words				//лист
{
	char word[128];
	char *value;
	struct Words *next;
	struct Words *prev;
};								

struct Dictionary		//бинарное дерево разделяет на гласные согласные 
{
	struct Dictionary * left_ptr; //гласные
	struct Dictionary * right_ptr; //согласнык
	struct Words * list; //лист
};

void check_record(char *); //проверка записи слова
void normalization(char *); //нормализация слова. Перевод с верхнего регистра в нижний
struct Words *add_word(char *, char *);


int main()
{
	char word[] = WORD;
	check_record(word);
	normalization(word);

	return 0;
}

void check_record(char * word) //проверка записи слова
{
	int i;
	char *test;
	char special_characters[24] = { '!', '@', '"', '№','#', ';', '$', '%','^', ':', '&', '?', '*','(' , ')', '}', '{', '[', ']', '|', '/', '\\', ',' , '.'}; //массив спецсимволов
	for (i = 0; i < 24 ; ++i)
	{
		if (strrchr(word, special_characters[i])) //проверка на спец символы в слове
		{
			printf("error write word");
			break;
		}
	}
}

void normalization(char *word) //нормализация слова. Перевод с верхнего регистра в нижний
{
	int i = 0;
	while (word[i])                           // пока не конец строки
	{
	word [i] = tolower(word[i]);  // преобразовать текущий символ строки в строчный
		++i;                                   // инкремент индекса символов в строке
	}
}

struct Words *add_word(char *word, char *value)
{
	return NULL;
}

//нормализация
//списоки по словам 
//
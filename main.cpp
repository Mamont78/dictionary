#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD "Hello&"

struct Words                                   //лист
{
	char word[128];
	char *value;
	struct Words *next;
	struct Words *prev;
};

struct Dictionary                              //бинарное дерево раздел€ет на гласные согласные
{
	struct Dictionary *left_ptr;              //гласные
	struct Dictionary *right_ptr;             //согласнык
	struct Words *list;                        //лист
};

void check_record( char * );                     //проверка записи слова
void normalization( char * );                    //нормализаци€ слова. ѕеревод с верхнего регистра в нижний
struct Words *add_word( char *, char * );

int main()
{
	char word[] = WORD;
	check_record( word );
	normalization( word );
	return 0;
}


void check_record( char *word )                  //проверка записи слова
{
	int i;
	char *test;
	char special_characters[] = { '!', '@', '"', 'є','#', ';', '$', '%','^', ':', '&', '?', '*','(' , ')', '}', '{', '[', ']', '|', '/', '\\', ',' , '.'}; //массив спецсимволов
	for (i = 0; i < strlen(special_characters); ++i)
	{
		if ( strrchr( word, special_characters[i] ) )//проверка на спец символы в слове
		{
			printf("error write word");
			break;
		}
	}
}

void normalization(char *word) //нормализаци€ слова. ѕеревод с верхнего регистра в нижний
{
	int i = 0;
	while (word[i])
	{
		word[i] = tolower(word[i]);  // преобразовать текущий символ строки в строчный
		++i;
	}
}

struct Words *add_word( char *word, char *value )
{
	return NULL;
}
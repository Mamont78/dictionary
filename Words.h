#ifndef WORDS_H_
#define WORDS_H_

struct Word //слово
{
	char *word;
	char *value;
};

struct List_words //список слов
{
	struct Word wd;
	struct List_words *next;
};

int add_word(struct List_words **, struct Word const *);
struct List_words *find(struct List_words *, char *, int );
int delet_word(struct List_words *, char *, int ); 	//удаление из списка
struct Word *find_word(struct List_words *, char *,int );


#endif /* WORDS_H_ */

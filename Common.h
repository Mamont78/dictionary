#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
struct Dictionary;
struct Word;


int check_record( char * );                     //ïðîâåðêà çàïèñè ñëîâà
void normalization( char * );                    //íîðìàëèçàöèÿ ñëîâà. Ïåðåâîä ñ âåðõíåãî ðåãèñòðà â íèæíèé
int control_lengths( char * );					//ïðîâåðêà äëèíû ñëîâà
int add_input_dictionary(struct Dictionary *, char *);  //äîáàâëåíèå ñëîâ èç ñëîâàðÿ
int add_output_dictionary(struct Dictionary *, char *);
size_t get_line_buffer(char *buffer);
int add_input_word(struct Dictionary * dict, char * buffer);
int add_output_dictionary(struct Dictionary * dict, char * path);
int dictionary_passage(struct Dictionary *dict, FILE *Diction);
struct List_words *list_words_passage(struct List_words *list, FILE *Diction);

#endif /* COMMON_H_ */

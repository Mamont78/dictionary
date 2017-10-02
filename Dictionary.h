#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Words.h"

struct Dictionary
{

	struct Dictionary *left_ptr;
	struct Dictionary *right_ptr;
	struct List_words *list;
};

int add_dictionary( struct Dictionary *, struct Word *, int );
struct List_words *find_dictionary(struct Dictionary * dict, char * wd);
struct List_words *delete_dictionary(struct Dictionary *dict, char *wd);

#endif /* DICTIONARY_H_ */

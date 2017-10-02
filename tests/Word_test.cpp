#include "gtest/gtest.h"
#include "Words.h"
#include "Common.h"
#include "Dictionary.h"
#include "iostream"

TEST(Word_tests, add_word) //1 название теста 2 названиет текущего теста
{
	struct Word input_word;
	memset( &input_word, NULL, sizeof(Word));
	struct  Dictionary input_unit;
	memset(&input_unit, NULL, sizeof(Dictionary));
	input_word.word = strdup("солнце");
//	input_word.value = strdup("со213123123123лнце"); 
	int test_number = 0;
	int val1 = add_Dictionary(&input_unit, &input_word, test_number);
	ASSERT_EQ(val1, -1);
	free(input_word.word);
	//delet_word(input_unit.list, del, 0);
}

TEST(Word_tests, find_word)
{
	int test_number = 0;
	struct Word input_word;
	memset(&input_word, NULL, sizeof(Word));
	struct  Dictionary input_unit;
	memset(&input_unit, NULL, sizeof(Dictionary));
	input_word.word = strdup("солнце");
	input_word.value = strdup("светит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("авилин");
	input_word.value = strdup("лунит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("дом");
	input_word.value = strdup("домит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("авилов");
	input_word.value = strdup("березит");
	add_Dictionary(&input_unit, &input_word, test_number);
	test_number = 0;
	find_word(find_dictionary(&input_unit, input_word.word), input_word.word, 0 );
	free(input_word.word);
	free(input_word.value);
}

TEST(Word_tests, delet_word)
{
	int test_number = 0;
	int val1;
	struct Word input_word;
	memset(&input_word, NULL, sizeof(Word));
	struct Word *wordq;
	struct  Dictionary input_unit;
	memset(&input_unit, NULL, sizeof(Dictionary));
	input_word.word = strdup("авилод");
	input_word.value = strdup("светит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("авилок");
	input_word.value = strdup("лунит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("авилор");
	input_word.value = strdup("домит");
	test_number = 0;
	add_Dictionary(&input_unit, &input_word, test_number);
	memset(&input_word, NULL, sizeof(Word));
	input_word.word = strdup("авилов");
	input_word.value = strdup("березит");
	add_Dictionary(&input_unit, &input_word, test_number);
	test_number = 0;
	input_word.word = strdup("авилов");
	input_word.value = strdup("лунит");
	val1 = delet_word(find_dictionary(&input_unit, input_word.word), input_word.word, 0);
	ASSERT_EQ(val1, 0);
	free(input_word.word);
	free(input_word.value);
}
#include "gtest\gtest.h"
#include "Common.h"
#include "Words.h"
#include "Dictionary.h"


TEST(Dictionary_tests, test_unit) //1 название теста 2 названиет текущего теста
{
	struct Word input_word;
	struct  Dictionary input_unit;
	input_unit.left_ptr = NULL;
	input_unit.right_ptr = NULL;
	input_word.word = strdup("солнце");
	input_word.value = strdup("sfjkslkdjflksjd");
	int test_number = 0;
	int val1 = add_Dictionary(&input_unit, &input_word, test_number);
	ASSERT_EQ(val1, 0);
	test_number = -1;
	val1 = add_Dictionary(&input_unit, &input_word, test_number);
	ASSERT_EQ(val1, -1);
	free(input_word.word); 
	free(input_word.value);
}
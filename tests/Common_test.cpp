#include "gtest/gtest.h"
#include "Common.h"
#include "Words.h"

TEST(Common_tests, normalization_test) //1 название теста 2 названиет текущего теста
{
	struct Word input_word;
	int val;
	input_word.word = strdup("HSI");
	normalization(&input_word);
	EXPECT_STREQ(input_word.word, "hsi" );
	free(input_word.word);
}

TEST(Common_tests, check_record_test)
{
	struct Word input_word;
	input_word.word = strdup("#&#WS");
	int val1 = check_record(&input_word);
	ASSERT_EQ(val1, -1);
	free(input_word.word);
}

TEST(Common_tests, control_lengths_test)
{
	struct Word input_word;
	int val;
	input_word.word = strdup("длвыфоапфыжлвукжцфйшю€бафжэывшкфцылатфвыжэвшнракфыцунажоыварюфыцугокнфоылу");
	val = control_lengths(&input_word);
	EXPECT_EQ(val, 0);
	free(input_word.word);
}
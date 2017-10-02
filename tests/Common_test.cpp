#include "gtest/gtest.h"
#include "Common.h"
#include "Words.h"

TEST(Common_tests, apper) //1 название теста 2 названиет текущего теста
{
	struct Word input_word;
	input_word.word = strdup("HSI");
	normalization(&input_word);
	EXPECT_STREQ(input_word.word, "hsi" );
	int val1 = check_record(&input_word);
	ASSERT_EQ(val1, 1);
	val1 = control_lengths(&input_word);
	ASSERT_EQ(val1, 1);
	free(input_word.word);
}
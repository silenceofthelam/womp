#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/word.h"

#define RUN_TEST(F,T, ...) assert((((F)(__VA_ARGS__))==(T))); tests_passed++

int run_all_tests()
{
	int tests_passed = 0, tests_failed = 0;

	RUN_TEST(strcmp, 0, permutate("tree", "dog"), "treedog");
	RUN_TEST(strcmp, 0, capitalize_nth_character("dog", 1), "Dog");
	RUN_TEST(strcmp, 0, capitalize_nth_character("Hello", 1), "Hello");
	RUN_TEST(strcmp, 0, capitalize_nth_character("bushes", 3), "buShes");
	RUN_TEST(strcmp, 0, prepend_string("what", "!"), "!what");
	RUN_TEST(strcmp, 0, append_string("what", "!"), "what!");

	printf("Tests Passed: %d\n", tests_passed);
	printf("Tests Failed: %d\n", tests_failed);

	return tests_failed;
}

int main(int argc, char** argv)
{
	return run_all_tests();
}


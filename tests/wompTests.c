#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "./wompTests.h"
#include "../src/womp.h"

#define RUN_TEST(F,T, ...) assert((((F)(__VA_ARGS__))==(T))); tests_passed++

int main(int argc, char** argv)
{
	return run_all_tests(argv[1]);
}

int run_all_tests(char *num_words)
{
	int tests_passed = 0, tests_failed = 0;
	char wordlist_file[30];

	RUN_TEST(print_to_stdout, atoi(num_words));
	RUN_TEST(strcmp, 0, permutate("tree", "dog"), "treedog");

	printf("Tests Passed: %d\n", tests_passed);
	printf("Tests Failed: %d\n", tests_failed);

	return tests_failed;
}

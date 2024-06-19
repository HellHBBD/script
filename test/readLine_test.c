#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cursorStyle.h>
#include <readLine.h>

typedef struct tc {
	char *testcase;
	char *answer;
} Testcase;

#define SIZE 5
const Testcase tcs[] = { { "hello\n", "hello" },
			 { "asdfjk;lasjroieafj;;wefi\n",
			   "asdfjk;lasjroieafj;;wefi" },
			 { "test\nasdf\n", "test" },
			 { "", "asdf" },
			 { "egsneobn", "egsneobn" } };

void test_readLine(int number)
{
	char *result = readLine();
	char *answer = tcs[number].answer;
	if (result != NULL && strcmp(result, answer) == 0) {
		FONT(GREEN);
		FONT(BOLD);
		printf("pass testcase %d\n", number);
		FONT(DEFAULT);
	} else {
		FONT(RED);
		FONT(BOLD);
		printf("fail testcase %d ", number);
		FONT(DEFAULT);
		if (result)
			printf("%s -> %s\n", result, answer);
		else
			printf("NULL -> %s\n", answer);
	}
	free(result);
}

void testcaseGenerate()
{
	FILE *temp = fopen("temp", "w+");
	if (!temp) {
		perror("Failed to open temp file");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++) {
		fputs(tcs[i].testcase, temp);
	}
	fclose(temp);

	if (freopen("temp", "r", stdin) == NULL) {
		perror("Failed to redirect stdin");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SIZE; i++) {
		test_readLine(i);
	}
	remove("temp");
}

int main()
{
	testcaseGenerate();
	return 0;
}

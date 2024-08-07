#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readLine.h>

char *readLine()
{
	char *result = malloc(sizeof(char) * 1);
	result[0] = '\0';
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		int length = strlen(result);
		result = realloc(result, sizeof(char) * (length + 1));
		result[length] = c;
		result[length + 1] = '\0';
	}
	return result;
}

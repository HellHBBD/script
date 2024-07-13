#include <store.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fread_string(char **string, FILE *file) {
	unsigned length = getw(file);
	*string = malloc(sizeof(char) * length);
	fread(*string, sizeof(char), length, file);
}

void fwrite_string(char *string, FILE *file) {
	if (!string) {
		return;
	}
	unsigned length = strlen(string) + 1;
	putw(length, file);
	fwrite(string, sizeof(char), length, file);
}

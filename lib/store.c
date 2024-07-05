#include <store.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fread_string(char **string, FILE *file) {
	size_t length;
	fread(&length, sizeof(length), 1, file);
	*string = malloc(sizeof(char) * length);
	fread(*string, sizeof(char), length, file);
}

void fwrite_string(char *string, FILE *file) {
	if (!string) {
		return;
	}
	size_t length = strlen(string) + 1;
	fwrite(&length, sizeof(length), 1, file);
	fwrite(string, sizeof(char), length, file);
}

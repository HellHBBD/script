#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *toUpperCase(char *string) {
	char *result = strdup(string);
	for (char *c = result; *c; c++) {
		if (*c >= 'a' && *c <= 'z')
			*c += ('A' - 'a');
	}
	return result;
}

void header_create(char *path, char *name)
{
	char *path_name = NULL;
	asprintf(&path_name, "%s/%s.h", path, name);

	char *upper = toUpperCase(name);

	FILE *file = fopen(path_name, "w");
	fprintf(file, "#ifndef %s_H\n#define %s_H\n\n#endif\n", upper, upper);
	fclose(file);

	free(upper);
	free(path_name);
}

void library_create(char *path, char *name)
{
	char *path_name = NULL;
	asprintf(&path_name, "%s/%s.c", path, name);

	FILE *file = fopen(path_name, "w");
	fprintf(file, "#include \"%s.h\"\n", name);
	fclose(file);

	free(path_name);
}

int main(int argc, char **argv)
{
	switch (argc) {
	case 2:
		header_create(".", argv[1]);
		library_create(".", argv[1]);
		break;
	case 4:
		header_create(argv[2], argv[1]);
		library_create(argv[3], argv[1]);
		break;
	default:
		puts("Error: Invalid arguments");
		return 0;
	}
	return 0;
}

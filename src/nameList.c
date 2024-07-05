#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readLine.h>
#include <store.h>

struct Name {
	char *name;
	struct Name *next;
};

struct List {
	size_t count;
	struct Name *head;
};

struct List *list = NULL;
/* char *filename = "/home/hellhbbd/scripts/data/nameList/data.bin"; */
char *filename = "data.bin";

void add(char *name)
{
	struct Name *new_name = malloc(sizeof(struct Name));
	new_name->name = strdup(name);
	new_name->next = list->head;
	list->head = new_name;
	list->count++;
}

void pop() {
	struct Name *prev = list->head;
	struct Name *curr = prev->next;
	list->head = curr;
	free(prev->name);
	prev->name = NULL;
	free(prev);
	prev = NULL;
	list->count--;
}

void delete(size_t index)
{
	if (index >= list->count) {
		puts("out of index");
		return;
	} else if (index == 0) {
		pop();
		return;
	}
	struct Name *prev = list->head;
	for (; index != 1; index--) {
		prev = prev->next;
	}
	struct Name *curr = prev->next;
	prev->next = curr->next;
	free(curr->name);
	curr->name = NULL;
	free(curr);
	curr = NULL;
	list->count--;
}

void print()
{
	if (list->head == NULL) {
		puts("empty name list");
		return;
	}
	size_t index = 0;
	for (struct Name *head = list->head; head; head = head->next) {
		printf("[%ld] %s\n", index, head->name);
		index++;
	}
}

void read()
{
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
		return;
	}
	size_t count;
	fread(&count, sizeof(count), 1, file);
	while (count--) {
		char *temp = NULL;
		fread_string(&temp, file);
		add(temp);
		free(temp);
	}
	fclose(file);
}

void write()
{
	FILE *file = fopen(filename, "wb");
	if (file == NULL) {
		perror("Error");
		return;
	}
	size_t count = list->count;
	fwrite(&count, sizeof(count), 1, file);
	struct Name *prev = list->head;
	for (struct Name *curr = prev; prev; prev = curr) {
		curr = curr->next;
		fwrite_string(prev->name, file);
		free(prev->name);
		prev->name = NULL;
		free(prev);
		prev = NULL;
	}
	fclose(file);
}

#define CLEAN_BUFFER()                          \
	{                                       \
		char c;                         \
		while ((c = getchar()) != '\n') \
			;                       \
	}

int main()
{
	list = malloc(sizeof(struct List));
	list->head = NULL;
	list->count = 0;
	size_t option;

	// read data
	read();

	while (1) {
		// print data
		print();
		printf("\n\n[0] = exit\n[1] = add name\n[2] = delete name\n\n(0/1/2): ");
		scanf("%ld", &option);
		CLEAN_BUFFER();
		char *line;
		switch (option) {
		case 0:
			// write data
			write();
			free(list);
			list = NULL;
			return 0;
		case 1:
			// add
			line = readLine();
			add(line);
			free(line);
			line = NULL;
			break;
		case 2:
			// delete
			scanf("%ld", &option);
			CLEAN_BUFFER();
			delete (option);
			break;
		default:
			puts("invalid option");
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <readLine.h>

char *getMsg(char *arg)
{
	char *msg;
	asprintf(&msg, "scp -r /home/hellhbbd/coding/java/112PD2/hw%s/*.java pd2:~/hw", arg);
	return msg;
}

int main(int argc, char **argv)
{
	char *line;
	if (argc < 2) {
		line = readLine();
	} else {
		line = argv[1];
	}
	char *msg = getMsg(line);
	/* system(msg); */
	printf("%s\n", msg);
	free(msg);
	if (argc < 2) {
		free(line);
	}
	return 0;
}

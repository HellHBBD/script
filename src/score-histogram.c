#include <stdio.h>
#include <stdlib.h>
#include <readLine.h>

int main(int argc, char **argv) {
	char *syear, *sem, *co_no, *class_code;
	if (argc < 4) {
		printf("syear: ");
		syear = readLine();
		printf("sem: ");
		sem = readLine();
		printf("co_no: ");
		co_no = readLine();
		printf("class_code: ");
		class_code = readLine();

		printf("https://qrys.ncku.edu.tw/ncku/histogram.asp?syear=0%s&sem=%s&co_no=%s&class_code=%s\n", syear, sem, co_no, class_code);

		free(syear);
		free(sem);
		free(co_no);
		free(class_code);
	} else {
		syear = argv[1];
		sem = argv[2];
		co_no = argv[3];
		if (argc >= 5) {
			class_code = argv[4];
		} else {
			class_code = "";
		}

		printf("https://qrys.ncku.edu.tw/ncku/histogram.asp?syear=0%s&sem=%s&co_no=%s&class_code=%s\n", syear, sem, co_no, class_code);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int count, char** argv){
	int i;
	for(i=1;i<count;i++){
		char buffer[100];
		char *str= argv[i];
		FILE *fp = fopen(str, "r");
		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}

		while(fgets(buffer, 100, fp) != NULL){
			printf("%s",buffer);
		}
		printf("\n");
		fclose(fp);
	}
	exit(0);
}

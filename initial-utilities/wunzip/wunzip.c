#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(int args, char** argv){
	unsigned char current;
	unsigned int count;
	int i;
	FILE *in;
	if((in = fopen(argv[1], "rb")) == NULL){
		printf("Cannot open file name for reading\n");
		exit(1);
	}

	while(!feof(in)){
		fread(&count, sizeof(count), 1, in);
		fread(&current, sizeof(current), 1, in);
		for(i=0; i<count; i++){
			fwrite(&current, sizeof(current), 1, stdout);
		}

	}
	printf("\n");
	fclose(in);
	exit(0);
}

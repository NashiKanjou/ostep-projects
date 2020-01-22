#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(int args, char** argv){
	unsigned char current, next;
	unsigned int count;
	FILE *source;

	if ((source = fopen(argv[1], "rb")) == NULL){
		printf("Cannot open file name for reading\n");
		exit(1);
	}


	fread(&current, sizeof(current), 1, source);
	count = 1;
	while(!feof(source)){
		while(fread(&next, sizeof(next), 1, source)==1){
			if (current == next){
				count++;
			}else{
				break;
			}
		}
		fwrite(&count, sizeof(count), 1, stdout);
		fwrite(&current, sizeof(current), 1,stdout);
		current = next;
		count = 1;
	}
	fclose(source);
	exit(0);
}

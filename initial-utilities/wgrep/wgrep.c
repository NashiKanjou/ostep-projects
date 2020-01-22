#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int count, char** argv){
	if(count <=1||count>3){
		printf("wgrep: Error, args should be 2 or 3 only\n");
		exit(1);
	}
	char* term = argv[1];
	if(count==2){
		puts("User input mode... type \"exit\" to break the loop");
		char pt[100];
		while((fgets(pt,100,stdin)) != NULL){
			char* ptr = strstr(pt,term);
			if(ptr!=NULL){
				puts(pt);
			}
			if(strstr(pt,"exit")==pt){
				exit(0);
			}
		}
	}else{
		int i;
		for(i=2;i<count;i++){
			char *str= argv[i];
			FILE *fp = fopen(str, "r");
			if (fp == NULL) {
				printf("wgrep: cannot open file\n");
				exit(1);
			}

				char pt[100];
				while((fgets(pt,100,fp))){
					char* ptr = strstr(pt,term);
					if(ptr!=NULL){
						puts(pt);
					}

				}

			fclose(fp);
		}
	}
	exit(0);
}

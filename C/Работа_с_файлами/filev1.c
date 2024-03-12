#include <stdio.h>

void main(){
	FILE* fp;
	char string;
	char name[] = "../../C/my.txt";
	if ((fp = fopen(name, "r")) == NULL){
		printf("Could not open file.");
		return;
	} else{
		fprintf(fp, "%c", string);
	}
	printf("%c", string);
	printf("success");
	fclose(fp);
}

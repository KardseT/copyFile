#include <cstdio>
#include <cstdlib>

#define PATHLENGTH 64

int main(int argc, char *argv[]){
	FILE *inFptr, *outFptr;
	char inPath[PATHLENGTH], outPath[PATHLENGTH];
	char ch;
	unsigned int count=0;

	if(argc==3){
		inFptr=fopen(argv[1], "r");
		outFptr=fopen(argv[2], "a");
	}
	else{
		printf("輸入檔案:\n");
		scanf("%64s", inPath);
		inFptr=fopen(inPath, "r");
		printf("輸出檔案:\n");
		scanf("%64s", outPath);
		outFptr=fopen(outPath, "a");
	}

	if(inFptr==NULL || outFptr==NULL){
		perror("The following error occurred");
		return 1;
	}

	//Attention Operator Precedence
	while( (ch=fgetc(inFptr)) != EOF){
		fputc(ch, outFptr);
		count++;
	}

	printf("Copy is done!\n");
	printf("Total word copied is: %d\n", count);

	fclose(inFptr);
	fclose(outFptr);

	system("PAUSE");
	return 0;
}
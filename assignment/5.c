#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	FILE *fps;
	int fd;
	char cha;
	char c;
	int wordCount = 0;
	int charCount = 0;
	int lineCount = 0;
	int wordState = 0;

	if(argc < 2) {
		fprintf(stderr,"사용법: %s readCount\n",argv[0]);
		exit(1);
		}

	if((fd = open(argv[1],O_RDONLY))==-1){
		perror(argv[1]);
		exit(2);
		}
	do{
		fscanf(fps, "%c", &cha);
       		 printf("%c", cha);
        if (cha >= 'A' && cha <= 'z') { 
            charCount++;

            if (wordState == 0) {
                wordState = 1;
            }
        }
        else {
            if (wordState == 1) {
                if (cha == '(') {
                    wordState = 2;
                }
                else if (cha == ' ' || cha == ',' || cha == '.') 			{
                    	wordState = 0;
                   	 wordCount++;
                	}
         
            else if (wordState == 2) {
                if (cha == ')') {
                    wordCount++;
                    wordState = 0;
                }
            }
        }
        if (cha == '\n') {
            lineCount++;
       	 }
	}
    }while (c == 'Y');

	close(fd);
	exit(0);
		
	
}

	


	

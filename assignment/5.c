#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 512
#include <stdlib.h>
/* 파일 크기를 계산 한다 */
int main(int argc, char *argv[]) 
{
   char buffer[BUFSIZE];
   char cha;
   int charCount;
   int wordCount;
   int lineCount;
   int wordState = 0;
   int fd;
   ssize_t nread;
   if ((fd = open(argv[1], O_RDONLY)) == -1) 
      perror(argv[1]);
	while( (nread = read(fd, buffer,    BUFSIZE)) > 0){
		if(cha >= 'A' && cha <= 'z'){
			charCount++;
			if(wordState == 0){
				wordState = 1;
			}
		  }
		else {
			if(wordState == 1){
				if(cha =='('){
					wordState = 2;
				  }
			else if(cha ==' '||cha==','||cha=='.'){
				wordState = 0;
				wordCount++;
				}
			  }
		else if(wordState ==2){
			if(cha == ')'){
				wordCount++;
				wordState = 0;
				}
			}
		}
		if(cha == '\n'){
			lineCount++;
		}
	}
	close(fd);
	printf("문자 수: %d  단어 수:%d  줄 수:%d",charCount,wordCount,lineCount);
	exit(0);
}

			
		




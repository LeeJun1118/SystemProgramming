#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "student.h"
#define START_ID 1201001

int main(int argc, char* argv[]){
	struct student record;
	char c;
	int id;
	FILE *fp;
	if(argc < 2){
		fprintf(stderr,"사용법 %s 파일명\n",argv[0]);
		exit(1);
	}
	if((fp = fopen(argv[1],"rb")) == NULL){
		fprintf(stderr,"파일열기오류\n");
		exit(2);
	}
	do{
		printf("검색할 학번 입력:");
		if(scanf("%d",&id) == 1){
			fseek(fp, (id - START_ID)*sizeof(record),SEEK_SET);
			if(fread((char*)&record, sizeof(record),1,fp) > 0 && record.id != 0){
				printf("학번 : %d 이름 : %s 점수 : %d\n",record.id,record.name,record.score);
				
			} else {
				printf("레코드 %d 없음",record.id);
				}
		}
				
			else {
				printf("입력오류\n");
			}
			printf("계속하시겠습니까?Y/N : ");
			__wur(stdin);
			scanf("%c",&c);
			
		}while(c == 'Y' || c == 'y');
		fclose(fp);
		exit(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "student.h"
#define START_ID 1201001

int main(int argc, char* argv[]){
	struct student record;
	int id;
	char c;
	FILE *fp;

	if(argc < 2){
	fprintf(stderr,"사용법 %s 파일이름\n",argv[0]);
	exit(1);
	}
	if((fp = fopen(argv[1],"rb+")) == NULL){
		fprintf(stderr,"파일 열기 오류\n");
		exit(2);
	}
	do{
		printf("수정할 학생의 학번 입력 :");
		if(scanf("%d",&id) == 1){
			fseek(fp, (id - START_ID) * sizeof(record), SEEK_SET);
			if(fread((char*)&record,sizeof(record),1,fp) > 0 && record.id != 0){
				printf("학번 : %d 이름 : %s 점수 : %d\n",record.id,record.name,record.score);
				printf("수정할 점수 입력: ");
				scanf("%d",&record.score);
				fseek(fp,-sizeof(record),SEEK_CUR);
				fwrite((char*)&record, sizeof(record),1,fp);
				
			} else {
				printf("레코드 %d 없음\n",record.id);
			}
		} else {
			printf("입력오류\n");
		}
		printf("\n계속하시겠습니까? Y/N : ");
		__wur(stdin);
		scanf("%c",&c);
	}while(c == 'Y' ||c == 'y');
	fclose(fp);
	exit(0);
}

#include <stdio.h>
#include <unistd.h>
#include "student.h"
#include <stdlib.h>
#define START_ID 1201001

int main(int argc, char* argv[]){
	struct student record;
	FILE* fp;
	if(argc < 2){
		fprintf(stderr,"사용법 :%s 파일명\n",argv[0]);
		exit(1);
	}
	fp = fopen(argv[1],"wb");
	printf("학번 이름 점수 :\n");
	while(scanf("%d %s %d",&record.id, record.name, &record.score) == 3){
		fseek(fp, (record.id - START_ID) * sizeof(record) ,SEEK_SET);
		fwrite((char*)&record, sizeof(record),1,fp);
	}
	fclose(fp);
	return 0;
}

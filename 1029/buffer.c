#include <stdio.h>

void main(){
	int i,n,m,j;
	char c;
	printf("반복할 수 입력: ");
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
		printf("반복할 문자와 반복할 수 입력: ");
		getchar();
		//__wur(stdin);
		//__fpurge(stdin);
		scanf("%c %d",&c,&m);
		for(j = 1;j <=m; j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}

}

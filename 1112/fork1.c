#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	printf("[%d] 프로세스 시작 \n",getpid());
	pid = fork();//부모는 자식 프로세스의 id를 받고 자식은 0을 받는다.
	printf("[%d] 프로세스 : 리턴 값 %d\n",getpid(),pid);
}

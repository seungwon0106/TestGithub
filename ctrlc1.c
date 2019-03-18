#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//SIGINT에 대응하는 핸들러
void sigHandler(int sig)
{
	static int count =0;	//진입한 회수 count
	printf("OUCH! - |got signal %d\n", sig);
	if(count ==4)
	(void) signal(SIGINT, SIG_IGN);	//void선언한이유:return 값없는걸 명확히 선언
	count++;	//5개까지 count 해줌

}

//main 함수
int main()
{
	//SIGINT 신호가 수신되었을 때,
	//sigHandler() 함수가 호출되도록 등록

	signal(SIGINT, sigHandler);
	
		while (1)
		{
			printf("Hello, world\n");
			sleep(1);
		}


}

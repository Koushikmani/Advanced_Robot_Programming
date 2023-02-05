#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <signal.h>

void sig_handler(int signo)
{
	if(signo == SIGUSR1){
		printf("signal is received\n");
	}
}

int main(int argc, char* argv[]){
	
	signal(SIGUSR1, sig_handler);

	if (argc!=4){
		perror("Wrong number of input arguments, syntax should be:\nexer2_child0.exe <size> <fd0>\n");
		return -1;
	}
	
	
	int fd1 = atoi(argv[1]);
	int nstr1 = atoi(argv[2]);
	int nstr2 = atoi(argv[3]);
	int result1;
	char *myfifo = "/tmp/myfifo";
	
	
	fd1 = open(myfifo,O_WRONLY);
	if(fd1<-1){
		perror("sum failed in opennig fifo\n");
		exit(-1);
	}
		
	printf("Waiting for signal \n");
	pause();    //wait for signal
	
	result1=nstr1+nstr2;
		
	if(write(fd1, &result1, sizeof(result1))<0){
		perror("Error during child0 - father communication");
		exit(-3);
	}
	close(fd1);
	return 0;

}

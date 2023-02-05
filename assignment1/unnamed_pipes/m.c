#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
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
		perror("Wrong number of input arguments, syntax should be:\nchild1 <size> <fd1>\n");
		return -1;
	}
	
	int fd2 = atoi(argv[1]);
	int nstr1 = atoi(argv[2]);
	int nstr2 = atoi(argv[3]);
	int result2;
	
	printf("Waiting for signal \n");
	pause();    //wait for signal
	
	result2 = nstr1-nstr2;
	
	
	if(write(fd2, &result2, sizeof(result2))<0){
		perror("Error during child1 - father communication");
		close(fd2);
		exit(-3);
	}
	
	return 0;
	
}

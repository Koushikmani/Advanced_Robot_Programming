#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <signal.h>

int op(char operation, int a, int b);
int piping(char operator);
pid_t child;
int fd[2];
int n1,n2; 

int main(int argc, char *argv[]){
	

	char operator;

	

	if(pipe(fd)<0){
		perror("Error opening pipe between father and child");
		return -2;
	}
	
	printf(" Select operator (p for sum, m for subtraction, t for product and d for division) \n then press space and input the first number and then the second number \n for all consequent operations enter operation and then the number\n ");
	
	scanf("%c %i %i", &operator, &n1, &n2);
	op(operator,n1,n2);
	
	while(1){
        
        scanf("%c", &operator);
        if(operator == 'e'){   
           
		printf("Exiting Program!!!\n");
		close(fd[0]);     
		close(fd[1]);     
		exit(0);
        }
        else{
		scanf("%i", &n2);
		op(operator,n1,n2);
        }

	
	}
	return 0;
}


int op(char operator, int a, int b){ //Forking Function

	char str[16], nstr1[16], nstr2[16];
	sprintf(str, "%d", fd[1]);
	sprintf(nstr1, "%d", n1);
	sprintf(nstr2, "%d", n2);
		
	if(operator == 'p' || operator == 'P'){

		child=fork();
		if(child < 0){

			perror("Error in child generation");
			return -1;
		
		}
		
		if (child==0){

			close(fd[0]);
			char* args[] = {"./p", str, nstr1, nstr2, NULL};
			execvp(args[0], args);
			
		}
		else piping('p');
			
	}
		
		
	
	else if(operator == 'm' || operator == 'M'){

		child=fork();
		if(child < 0){

			perror("Error in child generation");
			return -1;
		
		}
		
		if (child==0){

			close(fd[0]);
			char* args1[] = {"./m", str, nstr1, nstr2, NULL};
			execvp(args1[0], args1);
			
		}
		else piping('m');	
	}
		
		


	else if(operator == 't' || operator == 'T'){

		child=fork();
		if(child < 0){

			perror("Error in child generation");
			return -1;
		
		}
		
		if (child==0){

			close(fd[0]);
			char* args2[] = {"./t", str, nstr1, nstr2, NULL};
			execvp(args2[0], args2);
			
		}	
		else piping('t');
	}
		
		

	
	else if(operator == 'd' || operator == 'D'){

		child=fork();
		if(child < 0){

			perror("Error in child generation");
			return -1;
		
		
		}
		if (child==0){

			close(fd[0]);
			char* args3[] = {"./d", str, nstr1, nstr2, NULL};
			execvp(args3[0], args3);
			
		}
		else piping('d');	
	}
		
		

	return 0;
	
}

int piping(char operator){

	int result;
	int res;
	
	sleep(1);

	kill(child,SIGUSR1); // signal to child process

	if(read(fd[0], &result, 80)<0){ // read from ppipe
		perror("Error in father - child communication");
		close(fd[0]);	
		exit(-3);
		
	}
	

	printf("%i %c %i = %i \n",n1, operator, n2, result); // print result
	n1=result; // result will be next first input for new operation	
	waitpid(child, &res, 0);	
	if (res < 0){     
        printf("\nThe child process terminated with an error!.\n");	 
	}
		 
}
			

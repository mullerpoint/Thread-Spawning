//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gary Muller
// Fall 2015
// CS 420 Assignment 1
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//A program that will spawn three child processes, print out the Parent and Child PIDs
//it will utilize fork() and execv() to spawn the processes 
//***specific implementations of these functions mean that this code will likely only run on RHEL***
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Header files - Standard libraries and classes
#include <stdio.h> //standard IO include
#include <sys/types.h> //typedef for unistd
#include <unistd.h> //process control functions
#include <pthread.h> //thread control functions
#include <errno.h> //error handling
#include <strings.h> //strerror()
//


//Global Variables and Defines

//

//Function Prototypes
void* threadProgram();
//

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void* main(int argv, char* argc[])
{
	//create variables
	pthread_t tid; //thread identifier
	int result;

	//print initial data
	printf("main: main thread here; pid is %lu, tid is %lu\n", getpid(), pthread_self());

	//spawn new thread
	result = pthread_create(&tid, NULL, threadProgram(), NULL);


	//check results and complete program accordingly
	if (result == 0)//successful creation of a seccond thread
	{
		printf("main: successfully created a new thread with TID of %lu\n", tid);
		
	}
	else //unsucessful creation of a seccond thread
	{
		printf(" ERR: error at line %d, error: %s", __LINE__, strerror(result));
	}

	pthread_join(tid, NULL);

	printf("main: second thread has terminated, main will now exit.\n");
}





void* threadProgram()
{
	printf("\tsecond thread here, my tid is %lu but I'm still in process %lu\n", pthread_self(), getpid());
}
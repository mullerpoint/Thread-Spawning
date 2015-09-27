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
void* threadProgram(void *);
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
	int result; //result return for pthread_create()

	//print initial data
	printf("main: main thread here; pid is %lu, tid is %lu\n", getpid(), pthread_self());

	//spawn new thread
	result = pthread_create(&tid, NULL, threadProgram, NULL); 
	/*
	tid - thread name return, 
	NULL - no atributes defined, 
	threadProgram - name of the function for thread 2 to run,
	NULL - no arguments for the function
	*/


	//check results and complete program accordingly
	if (result == 0)//successful creation of a seccond thread
	{
		//on success print the data about thread 2 from thread 1
		printf("main: successfully created a new thread with TID of %lu\n", tid);
	}
	else //unsucessful creation of a seccond thread
	{
		//print out the error returned by pthread_create()
		printf(" ERR: error at line %d, error: %s", __LINE__, strerror(result));
	}

	/*Make sure the thread 2 has finished before getting to the end of main 
	and killing the thread before it gets to execute*/
	pthread_join(tid, NULL);

	// final print out to end program
	printf("main: second thread has terminated, main will now exit.\n");
}//main





void* threadProgram(void * nothing)
{
	//print required info about thread 2
	printf("\tsecond thread here, my tid is %lu but I'm still in process %lu\n", pthread_self(), getpid());
}
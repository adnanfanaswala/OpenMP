/*
#-------------------------------------------------------------------------------
# Author: Adnan Fanaswala
# Created: 8th November 2012
# The code helps explain shared/private variables when using multiple threads
#-------------------------------------------------------------------------------
*/

#include <omp.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	//This is a private variable that keeps track of the current worker thread ID
	int currentWorkerThread;

	//Set the number of worker threads you want to create:
	omp_set_num_threads(8);

//Start the parallel region
#pragma omp parallel shared(currentWorkerThread)
	{	  
	  //Get the current thread 
	  currentWorkerThread = omp_get_thread_num();
	  printf("Executing OpenMP worker thread ID =  %d\n", currentWorkerThread);

		  if (currentWorkerThread == 3)
		  {
			std::cout << "\n I am being executed by worker thread ID = 3 \n" << std::endl;
		  }
	}

	system("PAUSE");
	return 0;
}
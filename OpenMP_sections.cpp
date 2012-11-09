/*
#-------------------------------------------------------------------------------
# Author: Adnan Fanaswala
# Created: 9th November 2012
# The code explains how to use Sections in OpenMP
#-------------------------------------------------------------------------------
*/

#include <omp.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{

	//Declaring a parallel region that will be broken down into disctinct parallel sections
	#pragma omp parallel sections
	{
		//Section 1
		#pragma omp section
		{ 
			printf ("This section is being executed by thread ID = %d, \n\n", omp_get_thread_num());
		}

		//Section 2
		#pragma omp section
		{ 
			printf ("This section is being executed by thread ID = %d, \n\n", omp_get_thread_num());
		}
	}

system("PAUSE");
return 0;

}
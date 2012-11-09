/*
#-------------------------------------------------------------------------------
# Author: Adnan Fanaswala
# Created: 8th November 2012
# The code explains how to multi-thread for loops using OpenMP 
# and achieves a 4x speed increase
#-------------------------------------------------------------------------------
*/

#include <omp.h>
#include <iostream>
#include <Windows.h>

//=============================================================================
// Timer Variables
//=============================================================================
double PCFreq = 0.0;
__int64 CounterStart = 0;

//=============================================================================
// Function Definitions
//=============================================================================
//Start Counter
void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

//This gives us a value in milli seconds
    //PCFreq = double(li.QuadPart)/1000.0;

//This gives us a value in seconds
    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

//Get Counter
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main(int argc, char* argv[])
{

//Sequential Region Code
int sumSequential = 0;

	StartCounter(); // This starts the timer
	for(int x=0; x < 1000; x++)
	{
		for(int y=0; y < 1000; y++)
		{
		sumSequential = sumSequential + x + y;
		}
	}  

std::cout << "Sequential execution of the summation yielded a result of : " << sumSequential << std::endl;
std::cout << "Sequential execution of the summation took a total time of : " << GetCounter() << " seconds \n" << std::endl;

//Parallel Region Code
int sumParallel = 0;

StartCounter(); // This starts the timer

#pragma omp parallel for reduction(+:sumParallel)
	for(int x=0; x < 1000; x++)
	{
		for(int y=0; y < 1000; y++)
		{
		sumParallel = sumParallel + x + y;
		}
	}  

std::cout << "Parallel execution of the summation yielded a result of : " << sumParallel << std::endl;
std::cout << "Parallel execution of the summation took a total time of : " << GetCounter() << " seconds \n" << std::endl;

system("PAUSE");
return 0;

}
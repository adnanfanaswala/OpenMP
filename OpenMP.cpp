#include <omp.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	// Should print this only on the Master thread (one time)
	std::cout << "This is being printed on the Master thread \n" << std::endl;

	//Set the number of worker threads you want to create:
	omp_set_num_threads(2);

	#pragma omp parallel
	{
		// This statement will run on each thread.
		// If there are 4 threads, this will execute 4 times in total
		std::cout << "In parallel region. This statement is being printed by each worker thread \n" << std::endl;
	}
	
	// The threads have been joined back with the Master thread
	// Will print just once since on the Master thread
	std::cout << "Out of parallel region. This is being printed on the Master thread" << std::endl;

	system("PAUSE");
	return 0;
}
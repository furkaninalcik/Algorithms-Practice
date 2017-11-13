#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
using namespace std;


void countingSort(int array[] , int size){

	int max = 0;

	int B[size];

	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];

		}
	}

	cout << "max: " << max << endl;



	int C[max+1]; 


	for (int i = 0; i < max+1; ++i)
	{

		C[i] = 0;

	}

	for (int i = 0; i < size; ++i)
	{
		C[array[i]] += 1;
	}
 	
 	for (int i = 1; i < max+1; ++i)
 	{

 		C[i] += C[i-1]; 
 	}

 	for (int i = 0; i < max+1; ++i)
 	{
 		cout << C[i] << "-";
 	}
 	cout << endl;

 	for (int i = size-1; i >= 0; --i)
 	{

 		B[C[array[i]]-1] = array[i];
 		C[array[i]]--;

 	}

 	for (int i = 0; i < size; ++i)
 	{

 		cout << B[i] << " * " ;
 	}


}


void radixSort(int array[], int size){

	for (int i = 0; i < size; ++i)
	{
		/* code */
	}

}

int main()
{
	int array[6];
	array[0] = 3;
	array[1] = 11;
	array[2] = 6;
	array[3] = 2;
	array[4] = 9;
	array[5] = 6;


	countingSort(array , 6);



	return 0;
}


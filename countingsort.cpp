#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

void countingSort(int array[], int size){

	int max = 0;
	int outputArray[size];
	for (int i = 0; i < size; ++i)
	{
		outputArray[i] = 0;
		if (array[i] > max)
		{
			max = array[i];
		}
		cout << array[i] << " - ";

	}

	int countArray[max+1];

	for (int i = 0; i < max+1; ++i)
	{
		countArray[i] = 0;
	}

	cout << endl << max << endl ;

	printf("\n");

	for (int i = 0; i < size; ++i)
	{
		countArray[array[i]]++;
	}
	for (int i = 0; i < max+1; ++i)
	{
		cout << countArray[i] << " - ";
	}


	cout << "**********" << endl;

	for (int i = 1; i < max+1; ++i)
	{
		countArray[i] += countArray[i-1];
	}
	for (int i = 0; i < max+1; ++i)
	{
		cout << countArray[i] << " - ";
	}
	cout << endl;


	for (int i = size-1; i >= 0; --i)
	{
		outputArray[countArray[array[i]]-1] = array[i];
		countArray[array[i]]--;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << outputArray[i] << " - ";
	}
	cout << endl;



}



int main()
{
	int array[5];
	array[0] = 6 ;
	array[1] = 11;
	array[2] = 8;
	array[3] = 17;
	array[4] = 8;
	countingSort(array, 5);




	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>
using namespace std;


void countingSort(int array[] , int size , int d){

	int max = 0;

	int B[size];

	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " + ";
		cout << "test: " << "digit: " << (int(array[i]/pow(10,d))%10)  << endl; 
		if ((int(array[i]/pow(10,d))%10) > max)
		{
			max = array[i];

		}
	}
	cout << endl;

	cout << "max: " << max << endl;



	int C[max+1]; 


	for (int i = 0; i < max+1; ++i)
	{

		C[i] = 0;

	}

	for (int i = 0; i < size; ++i)
	{
		int number = (int(array[i]/pow(10,d))%10);
		C[number] += 1;
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
		int number = (int(array[i]/pow(10,d))%10);
 		B[C[number]-1] = array[i];
 		C[number]--;

 	}

 	for (int i = 0; i < size; ++i)
 	{

 		cout << B[i] << " * " ;
 	}


}


void radixSort(int array[], int size , int digit){

	for (int i = 0; i < digit; ++i)
	{

		countingSort(array , size , i ); //i -> 0 1 2

	}

}

int main()
{
	int array[6];
	array[0] = 311;
	array[1] = 416;
	array[2] = 276;
	array[3] = 712;
	array[4] = 389;
	array[5] = 106;

	int digit = 3;
	int d =0 ;

	radixSort(array , 6 , digit);
	//countingSort(array , 6 , d);



	return 0;
}


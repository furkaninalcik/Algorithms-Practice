#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>
#include <time.h>   
using namespace std;

// C program for insertion sort
#include <stdio.h>
#include <math.h>


void time() {

  clock_t begin = clock();

  for (int i = 0; i < 90000000; ++i)
  {
  	i++;
  }

  clock_t end = clock();
  double elapsed_secs;
  cout << (elapsed_secs = double(end - begin) / CLOCKS_PER_SEC) << endl;
}




/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
 
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
 
 
 
/* Driver program to test insertion sort */
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int arr2[100000];
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
 
    for (int i = 0; i < 100000; ++i)
    {
    	arr2[i] = rand();
    	if (i == 42)
    	{
    		//cout << arr2[i] << "eee" << endl;
    	}
    }


    clock_t begin = clock();
 
    insertionSort(arr2, n2);
    printArray(arr2, n2);
 

    clock_t end = clock();

    double elapsed_secs;
  	cout << "Time elapsed: " << (elapsed_secs = double(end - begin) / CLOCKS_PER_SEC) << endl;



    return 0;
}
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


//////////////////LINEAR TIME SORTING/////////////////////////
void countingSort(int array[] , int size , int d){

  int max = 0;

  int B[size];

  for (int i = 0; i < size; ++i)
  {
    int number = (int(array[i]/pow(10,d))%10);
    if (number > max)
    {
      max = number;

    }
  }


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


  for (int i = size-1; i >= 0; --i)
  {
    int number = (int(array[i]/pow(10,d))%10);
    B[C[number]-1] = array[i];
    C[number]--;

  }

  for (int i = 0; i < size; ++i)
  {
    array[i] = B[i];
  }

}


void radixSort(int array[], int size , int digit){

  for (int i = 0; i < digit; ++i)
  {

    countingSort(array , size , i ); //i -> 0 1 2

  }

}

////////////////////////////////////////////////////////////



///////////////HEAP SORT////////////////////////////////


void max_heapify(int array[], int i, int size){

  if (2*(i+1)-1 > size)
  {
    return;
  }



  int temp = 0;
  i++;

  int largest = i-1;

  if (array[i-1] < array[2*i-1]  )
  {
    largest = 2*i-1;

  }
  if (array[largest] < array[2*i] )
  {

    largest = 2*i;
    
  }

  if (largest != i-1)
  {
    temp = array[i-1];
    array[i-1] = array[largest];
    array[largest] = temp;
    max_heapify(array, largest , size);
      
  }
  
}

void build_max_heap(int array[], int size){

  for (int i = size/2-1; i >= 0; --i)
  {
    max_heapify(array , i , size);

  }



}




void heapsort(int array[], int size){

  build_max_heap(array, size);

  int dynamic_size = size;

  for (int i = size; i >= 0; --i)
  {
    array[dynamic_size] = array[0];
    max_heapify(array, 0 ,--dynamic_size);

    //dynamic_size--;
  }


}
////////////////////////////////////////////////



////////////////////QUICK SORT///////////////////////


void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


////////////////////////////////////////////////


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

    int arr2[1000000];
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
 
    for (int i = 0; i < 1000000; ++i)
    {
    	arr2[i] = rand();
    	if (i == 42)
    	{
    		//cout << arr2[i] << "eee" << endl;
    	}
    }

    cout << "SORTING..." << endl;
    clock_t begin = clock();
 
    //radixSort(arr2, n2, 10);
    //heapsort(arr2, n2);
    quickSort(arr2, 0, n2);
    printArray(arr2, n2);
 

    clock_t end = clock();

    double elapsed_secs;
  	cout << "Time elapsed: " << (elapsed_secs = double(end - begin) / CLOCKS_PER_SEC) << endl;



    return 0;
}
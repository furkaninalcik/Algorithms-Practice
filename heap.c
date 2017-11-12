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



void build_max_heap(int array[], int size){

	for (int i = size/2-1; i >= 0; --i)
	{
		max_heapify(array , i , size);
		printf("eeee%d p %d\n", i , array[i]);
		for (int i = 0; i < size+1; ++i)
		{
			printf("%d\n", array[i] );
		}
		printf("**********\n");

	}



}

void max_heapify(int array[], int i, int size){

	if (2*(i+1)-1 > size)
	{
		return;
	}

	printf("-----------------\n");


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



int main()
{

	int array[] = {7,16,3,6,11,1,2};
	for (int i = 0; i < 7; ++i)
	{
		printf("-- %d\n", array[i] );
	}

	int size = 6;

	max_heapify(array,0 , size);

	for (int i = 0; i < 7; ++i)
	{
		printf("%d\n", array[i] );
	}

	printf("----------BUILDING--------- \n");

	int array2[] = {7,11,3,6,16,1,2};

	build_max_heap(array2,size);


	for (int i = 0; i < 7; ++i)
	{
		printf("%d\n", array2[i] );
	}

	printf("----------BUILDING A BIG HEAP --------- \n");


	int array3[] = {6,11,2,20,10,9,72,3,42,35,11,3,5,30,72};
	int size3 = 14;

	build_max_heap(array3,size3);


	for (int i = 0; i < 15; ++i)
	{
		printf("%d\n", array3[i] );
	}

	int array4[] = {6,11,2,20,10,9,72,3,42,35,11,3,5,30,72};

	printf("----------------HEAPSORT-------------\n");

	heapsort(array4,size);
	for (int i = 0; i < 15; ++i)
	{
		printf("%d\n", array4[i] );
	}


	return 0;
}
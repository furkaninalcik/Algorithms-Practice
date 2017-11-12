void build_max_heap(int array[], int size){

	for (int i = size/2-1; i > 0; --i)
	{
		max_heapify(array , i , size);
		printf("eeee%d p %d\n", i , array[i]);
	}



}

void max_heapify(int array[], int i, int size){

	if (2*(i+1)-1 > size)
	{
		return;
	}

	printf("-----------------\n");

	for (int i = 0; i < 7; ++i)
	{
		printf("-- %d\n", array[i] );
	}

	int temp = 0;
	i++;
	if (array[i-1] < array[2*i-1]  )
	{
		

		temp = array[i-1];
		array[i-1] = array[2*i-1];
		array[2*i-1] = temp;

	}
	if (array[i-1] < array[2*i] )
	{



		temp = array[i-1];
		array[i-1] = array[2*i];
		array[2*i] = temp;
		
	}

	max_heapify(array, 2*i-1 , size);


	max_heapify(array, 2*i , size);



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


	return 0;
}
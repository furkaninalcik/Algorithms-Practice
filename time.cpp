#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>
using namespace std;


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

int main()
{
	time();
	return 0;
}
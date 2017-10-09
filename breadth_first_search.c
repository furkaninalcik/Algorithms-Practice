#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Vertex {
  
  int number_of_adj_vertices ;

  char label;
  struct Vertex** adjList ;

  //struct Vertex** adjList = malloc(0)


  bool visited;

} Vertex;



void addVertex(Vertex* v1 , Vertex* v2){


  	v1->adjList = realloc( v1->adjList ,  sizeof(Vertex*) * (v1->number_of_adj_vertices+1));
  	v2->adjList = realloc( v2->adjList ,  sizeof(Vertex*) * (v2->number_of_adj_vertices+1));


  	v1->adjList[v1->number_of_adj_vertices] = v2; 
  	v2->adjList[v2->number_of_adj_vertices] = v1; 

	v1->number_of_adj_vertices++ ;   	
	v2->number_of_adj_vertices++ ;   
	

}


Vertex* queue[5];
int rear = -1;
int front = 0;
int queueItemCount = 0;

void enqueue(Vertex* v){

   queue[++rear] = v;
   queueItemCount++;

}
Vertex* dequeue(Vertex* v){

   queueItemCount--;
   return queue[front++];

}
bool isQueueEmpty() {
   return queueItemCount == 0;
}


void breadth_first_search(Vertex* source){

	Vertex* selected = source;

	while(!isQueueEmpty()){

		



	}
}


int main()
{
	
	Vertex vA  , vB , vS , vC , vG , vF , vD , vE , vH;

	vA = (Vertex) {.number_of_adj_vertices =  0 , .label =  'A' };
	vB = (Vertex) {.number_of_adj_vertices =  0 , .label =  'B' };
	vS = (Vertex) {.number_of_adj_vertices =  0 , .label =  'S' };
	vC = (Vertex) {.number_of_adj_vertices =  0 , .label =  'C' };
	vG = (Vertex) {.number_of_adj_vertices =  0 , .label =  'G' };
	vF = (Vertex) {.number_of_adj_vertices =  0 , .label =  'F' };
	vD = (Vertex) {.number_of_adj_vertices =  0 , .label =  'D' };
	vE = (Vertex) {.number_of_adj_vertices =  0 , .label =  'E' };
	vH = (Vertex) {.number_of_adj_vertices =  0 , .label =  'H' };


	addVertex(&vA , &vB);
	addVertex(&vA , &vS);

	addVertex(&vS , &vC);
	addVertex(&vS , &vG);
	
	addVertex(&vC , &vD);
	addVertex(&vC , &vE);
	addVertex(&vC , &vF);

	addVertex(&vF , &vG);

	addVertex(&vE , &vH);

	addVertex(&vH , &vG);






	char a = ((&vE)->adjList[0])->label;
	char b = ((&vE)->adjList[1])->label;
	
	printf("a label is %c\n", a );
	printf("another label is %c\n", b );











	free((&vA)->adjList);
	free((&vC)->adjList);
	free((&vE)->adjList);
	free((&vF)->adjList);
	free((&vG)->adjList);
	free((&vB)->adjList);
	free((&vS)->adjList);
	free((&vD)->adjList);
	free((&vH)->adjList);


	//v1 = { .number_of_adj_vertices =  0 , .label =  "v1" , .adjList []};


	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Vertex {
  
  int number_of_adj_vertices ;

  char label;
 
  bool visited;

  int distance ; // 100 is assumed to be larger than the distance between any pair of vertices in the graph
  

  struct Vertex** adjList ;

  //struct Vertex** adjList = malloc(0)


  struct Vertex* prevVertex;
  


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

Vertex* dequeue(){

   queueItemCount--;
   return queue[front++];

}

bool isQueueEmpty() {
   return queueItemCount == 0;
}


void breadth_first_search(Vertex* source){

	source->distance = 0;
	source->visited = true;

	enqueue(source) ;


	while(!isQueueEmpty()){
		Vertex * u = dequeue();
		//printf("u's label : %c\n", u->label );

		for (int i = 0; i < u->number_of_adj_vertices; ++i)
		{
			if (!(u->adjList[i]->visited))
			{
				u->adjList[i]->visited = true;
				(u->adjList[i]->distance) = u->distance+1;
				(u->adjList[i]->prevVertex) = malloc (sizeof(Vertex*));
				(u->adjList[i]->prevVertex) = u;
				enqueue(u->adjList[i]);


				printf("%c : %d\n", u->adjList[i]->label , u->adjList[i]->distance );

			}
		}





	}
}


int main()
{
	
	Vertex vA  , vB , vS , vC , vG , vF , vD , vE , vH , vT;

	vA = (Vertex) {.number_of_adj_vertices =  0 , .label =  'A' , .visited = false , .distance = 100};
	vB = (Vertex) {.number_of_adj_vertices =  0 , .label =  'B' , .visited = false , .distance = 100};
	vS = (Vertex) {.number_of_adj_vertices =  0 , .label =  'S' , .visited = false , .distance = 100};
	vC = (Vertex) {.number_of_adj_vertices =  0 , .label =  'C' , .visited = false , .distance = 100};
	vG = (Vertex) {.number_of_adj_vertices =  0 , .label =  'G' , .visited = false , .distance = 100};
	vF = (Vertex) {.number_of_adj_vertices =  0 , .label =  'F' , .visited = false , .distance = 100};
	vD = (Vertex) {.number_of_adj_vertices =  0 , .label =  'D' , .visited = false , .distance = 100};
	vE = (Vertex) {.number_of_adj_vertices =  0 , .label =  'E' , .visited = false , .distance = 100};
	vH = (Vertex) {.number_of_adj_vertices =  0 , .label =  'H' , .visited = false , .distance = 100};

	vT = (Vertex) {.number_of_adj_vertices =  0 , .label =  'T' , .visited = false , .distance = 100};


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


	addVertex(&vH , &vT);
	
	//addVertex(&vT , &vS);




	char a = ((&vE)->adjList[0])->label;
	char b = ((&vE)->adjList[1])->label;
	
	printf("a label is %c\n", a );
	printf("another label is %c\n", b );






	breadth_first_search(&vA);




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


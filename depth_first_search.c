#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex
{
	int color = 0; //0 -> not visited, 1 -> visited, 2-> finished
	char label ;
	Vertex** adjList ;
	Vertex** prevList ;

	adjList_len = 0;
	prevList_len = 0;

} Vertex;

void addVertex(Vertex* V1, Vertex* V2){

	V1->adjList = realloc(V1->adjList, sizeof(Vertex*)*(++V1->adjList_len));
	V2->prevList = realloc(V2->prevList, sizeof(Vertex*)*(++V2->prevList_len));
	
	V1->adjList[V1->adjList_len] = V2;
	V2->prevList[V2->prevList_len] = V1;

}
int main()
{
	Vertex vA  , vB , vS , vC , vG , vF , vD , vE , vH , vT;
	
	Vertex V_A = (Vertex) {.label = 'A'}; 
		
	return 0;
}




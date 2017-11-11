#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex
{
	int color; //0 -> not visited, 1 -> visited, 2-> finished
	char label ;
	struct Vertex** adjList ;
	struct Vertex** prevList ;

	int adjList_len;
	int prevList_len;

} Vertex;

void addVertex(Vertex* V1, Vertex* V2){

	V1->adjList = realloc(V1->adjList, sizeof(Vertex*)*(++(V1->adjList_len)));
	V2->prevList = realloc(V2->prevList, sizeof(Vertex*)*(++(V2->prevList_len)));
	
	V1->adjList[V1->adjList_len-1] = V2;
	V2->prevList[V2->prevList_len-1] = V1;

}

void depth_first_search(Vertex* Source){



}


int main()
{
	Vertex vA  , vB , vS , vC , vG , vF , vD , vE , vH , vT , vM;
	
	vA = (Vertex) {.color = 0 , .label = 'A', .adjList_len = 0, .prevList_len = 0}; 
	vB = (Vertex) {.color = 0 , .label = 'B', .adjList_len = 0, .prevList_len = 0}; 
	vS = (Vertex) {.color = 0 , .label = 'S', .adjList_len = 0, .prevList_len = 0}; 
	vC = (Vertex) {.color = 0 , .label = 'C', .adjList_len = 0, .prevList_len = 0}; 
	vG = (Vertex) {.color = 0 , .label = 'G', .adjList_len = 0, .prevList_len = 0}; 
	vF = (Vertex) {.color = 0 , .label = 'F', .adjList_len = 0, .prevList_len = 0}; 
	vD = (Vertex) {.color = 0 , .label = 'D', .adjList_len = 0, .prevList_len = 0}; 
	vE = (Vertex) {.color = 0 , .label = 'E', .adjList_len = 0, .prevList_len = 0}; 
	vH = (Vertex) {.color = 0 , .label = 'H', .adjList_len = 0, .prevList_len = 0}; 
	vT = (Vertex) {.color = 0 , .label = 'T', .adjList_len = 0, .prevList_len = 0}; 
	vM = (Vertex) {.color = 0 , .label = 'M', .adjList_len = 0, .prevList_len = 0}; 
	
	addVertex(&vA , &vB);
	addVertex(&vA , &vS);

	addVertex(&vS , &vC);

	addVertex(&vG , &vS);
	
	addVertex(&vC , &vD);
	
	addVertex(&vE , &vC);
	addVertex(&vE , &vH);
	addVertex(&vE , &vM);
	
	addVertex(&vF , &vC);
	addVertex(&vF , &vG);


	addVertex(&vH , &vT);


	addVertex(&vH , &vT);

	printf("%c\n", (vE.adjList[0])->label );
	printf("%c\n", (vE.adjList[1])->label );
	printf("%c\n", (vE.adjList[2])->label );


	return 0;
}




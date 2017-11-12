#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Vertex
{
	int color; //0 -> not visited, 1 -> visited, 2-> finished
	char label ;
	struct Vertex** adjList ;
	struct Vertex** prevList ;
	struct Vertex** predList;

	int adjList_len;
	int prevList_len;
	int predList_len;


} Vertex;


//Vertex* VertexArray = NULL;


void addVertex(Vertex* V1, Vertex* V2){

	V1->adjList = realloc(V1->adjList, sizeof(Vertex*)*(++(V1->adjList_len)));
	V2->prevList = realloc(V2->prevList, sizeof(Vertex*)*(++(V2->prevList_len)));
	
	V1->adjList[V1->adjList_len-1] = V2;
	V2->prevList[V2->prevList_len-1] = V1;

}

void depth_first_search(Vertex* Source, Vertex** VertexArray ){

	Source->color = 1;
	for (int i = 0; i < Source->adjList_len; ++i)
	{
		if ((Source->adjList[i])->color == 0)
		{
			(Source->adjList[i])->color = 1;
					
			printf("Vertex %c\n", (Source->adjList[i])->label  );
			Source->predList = realloc (Source->predList , sizeof(Vertex*)*(++(Source->predList_len)));
			Source->predList[Source->predList_len-1] = Source->adjList[i];
			depth_first_search((Source->adjList[i]) , VertexArray);
		}
		if (true)
		 {
		 	/* code */
		 }

	}
	Source->color = 2;

	bool finishedTree = true;

	
	for (int i = 0; i < 11; ++i)
	{
		//printf("%c \n" , VertexArray[i]->label);

		if (VertexArray[i]->color == 1)
		{
			finishedTree = false;
		}
	}
	if (finishedTree)
	{
		printf("We get a tree!\n");
		printf("Source : %c\n", Source->label );
		for (int i = 0; i < 11; ++i)
		{
			if (VertexArray[i]->color == 0)
			{
				depth_first_search((VertexArray[i]) , VertexArray);
			}
		}
	}


}


int main()
{
	Vertex vA  , vB , vS , vC , vG , vF , vD , vE , vH , vT , vM;

	vA = (Vertex) {.color = 0 , .label = 'A', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vB = (Vertex) {.color = 0 , .label = 'B', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vS = (Vertex) {.color = 0 , .label = 'S', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vC = (Vertex) {.color = 0 , .label = 'C', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vG = (Vertex) {.color = 0 , .label = 'G', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vF = (Vertex) {.color = 0 , .label = 'F', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vD = (Vertex) {.color = 0 , .label = 'D', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vE = (Vertex) {.color = 0 , .label = 'E', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vH = (Vertex) {.color = 0 , .label = 'H', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vT = (Vertex) {.color = 0 , .label = 'T', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	vM = (Vertex) {.color = 0 , .label = 'M', .adjList_len = 0, .prevList_len = 0 , .predList_len = 0}; 
	
	Vertex** VertexArray  = malloc(sizeof(Vertex*)*11);

	VertexArray[0] = &vA;
	VertexArray[1] = &vB;
	VertexArray[2] = &vS;
	VertexArray[3] = &vC;
	VertexArray[4] = &vG;
	VertexArray[5] = &vF;
	VertexArray[6] = &vD;
	VertexArray[7] = &vE;
	VertexArray[8] = &vH;
	VertexArray[9] = &vT;
	VertexArray[10] = &vM;

	addVertex(&vA , &vB);
	addVertex(&vA , &vS);

	addVertex(&vS , &vC);

	//addVertex(&vG , &vS);
	addVertex(&vS , &vG); // only for testing!!!
	
	addVertex(&vC , &vD);
	
	addVertex(&vE , &vC);
	addVertex(&vE , &vH);
	addVertex(&vE , &vM);
	
	addVertex(&vF , &vC);
	addVertex(&vF , &vG);


	addVertex(&vH , &vT);


	addVertex(&vH , &vT);

	//printf("%c\n", (vE.adjList[0])->label );
	//printf("%c\n", (vE.adjList[1])->label );
	//printf("%c\n", (vE.adjList[2])->label );

	depth_first_search(&vA, VertexArray);

	//printf("%c\n", (vA.predList[0])->label );


	return 0;
}




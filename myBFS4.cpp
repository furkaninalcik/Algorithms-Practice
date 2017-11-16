#include<iostream>
#include <list>
 
using namespace std;


class Graph{
	 int V;
	 list<int>* adj;
public:

	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);

};


Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];
	

}

void Graph::addEdge(int v, int w){
	cout << "ttt";
	adj[v].push_back(w);
}

void Graph::BFS(int s){


	bool visited[V];
	int parent[V];
	int distance[V];


	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	visited[0] = true;
	distance[0] = 0;
	parent[0] = -1; // no parent


	list<int> queue;

	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty()){

		s = queue.front();

		cout << " " << s;

		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
	
			if (!visited[*i])
			{
				distance[*i] = distance[s]+1;;
				parent[*i] = s;
				visited[*i] = true;	
				queue.push_back(*i);
			}			

		}

	}
	int label = 8;

	cout << endl << label << "'s parent is " << " \n"  << parent[label];
	cout << endl << label << "'s distance is " << " \n"  << distance[label];

}


int main()
{
    // Create a graph given in the above diagram
 	Graph g(9);
    g.addEdge(0, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 6);
    g.addEdge(6, 2);
    g.addEdge(6, 1);
    
    g.addEdge(8, 2);
    g.addEdge(1, 8);
    g.addEdge(8, 7);
    
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 7);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);
    cout << endl;


 
    return 0;
}
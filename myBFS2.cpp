
#include<iostream>
#include <list>
 
using namespace std;


class Graph{


	int V;
	list<int>* adj;
	list<int>* distance;
	list<int>* parent;




public:

	Graph(int V);

	void BFS(int s);

	void addEdge(int v, int w);

};


Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];
	
}


void Graph::addEdge(int v, int w){

	adj[v].push_back(w);
}


void Graph::BFS(int s){

	bool* visited = new bool[V];
	int* parent = new int[V];
	int* distance = new int[V];


	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
		parent[i] = 0;
	}

	parent[0] = -1;


	list<int> queue;

	queue.push_back(s);


	list<int>::iterator i; 

	while(!queue.empty()){

		s = queue.front();

		cout << s << " ";
		queue.pop_front();


		for (i = adj[s].begin(); i != adj[s].end() ; ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
				parent[*i] = s;
			}

		}

	}

}





int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(3, 1);
    g.addEdge(3, 6);
    g.addEdge(6, 2);
    g.addEdge(6, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 7);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 7);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(3);
    cout << endl;
 
    return 0;
}
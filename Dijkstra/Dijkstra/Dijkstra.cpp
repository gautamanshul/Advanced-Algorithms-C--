// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <memory>
#include <queue>
#include <functional>

#define INF 0X3F3F3F3F

class Graph {
	int V;
	std::list<std::pair<int, int>> *adj;
	Graph();
public:
	Graph(int V) : V(V), adj(new std::list<std::pair<int, int>> [V]) {
		//adj = std::make_unique<std::list<std::pair<int, int>>>() [V];

	}
	void addEdge(int u, int v, int w);
	const int & vertices() const { return V; }
	void shortestPath(int src);
};

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(std::make_pair(v, w));
	adj[v].push_back(std::make_pair(u, w));
}


void Graph::shortestPath(int src)
{
	//Create a priority queue (min heap) 
	std::priority_queue <std::pair<int, int>, std::vector <std::pair<int, int>>, std::greater<std::pair<int, int> > > pq;

	std::vector <int> distance(V, INF);
	std::vector <int> parent(V, -1);
	//Extract min from heap
	distance[src] = 0;
	pq.push(std::make_pair(distance[src], src));

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) {
			int vertex = (*itr).first;
			int weight = (*itr).second;

			if (distance[vertex] > distance[u] + weight) {
				parent[vertex] = u;
				distance[vertex] = distance[u] + weight;
				pq.push(std::make_pair(distance[vertex], vertex));
			}
		}
	}
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, distance[i]);

	printf("Vertex   Parent\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, parent[i]);
}

int main()
{
	// create the graph given in above fugure 
	int V = 9;
	Graph g(V);

	//  making above shown graph 
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

	return 0;
   
}


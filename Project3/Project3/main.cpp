#include "Graph.h"


int main()
{
	Graph graph;

	graph.AddVertex(0);
	graph.AddVertex(1);
	graph.AddVertex(2);
	graph.AddVertex(3);
	graph.AddVertex(4);
	graph.AddVertex(5);

	graph.AddEdge(0, 1, 5);
	graph.AddEdge(1, 2, 3);
	graph.AddEdge(2, 3, -8);
	graph.AddEdge(3, 4, -2);
	graph.AddEdge(4, 2, -2);
	graph.AddEdge(0, 5, 8);


	graph.BellmanFord(0);

	system("pause");
	return 0;
}
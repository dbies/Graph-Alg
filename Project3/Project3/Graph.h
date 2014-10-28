#include <map>
#include "Node.h"
#include <limits>
#include <vector>

class Graph
{
private:
	static const int maxC=INT_MAX;
	std::map<int,Node*> nodes;
public:
	void AddEdge(int start, int end, int cost=0);
	void AddVertex(int val);
	void DFSM(int st, std::map<int, bool> visited);
	void DFS(int st);
	void BellmanFord(int st);
};
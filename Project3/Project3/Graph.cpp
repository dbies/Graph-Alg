#include "Graph.h"
#include <iostream>

void Graph::AddEdge(int start, int end, int cost)
{
	Node *st = nodes.find(start)->second;
	Node *ed = nodes.find(end)->second;
	st->AddAdjNode(std::make_pair(cost, ed));

}
void Graph::AddVertex(int val)
{
	std::map<int, Node*>::iterator it = nodes.begin();
	it = nodes.find(val);
	if (it == nodes.end())
	{
		Node* node = new Node(val);
		nodes[val] = node;
		return;
	}
}
void Graph::DFSM(int st, std::map<int, bool> visited)
{
		int cur = st;
		visited.at(cur) = true;
		std::cout << cur << " ";

		for (unsigned int i = 0 ; i<nodes.at(cur)->adjNodes.size() ; i++)
		{
			int curv = nodes.at(cur)->adjNodes.at(i).second->value;
			if (visited.at(curv) == false)
			{
				DFSM(nodes[cur]->adjNodes.at(i).second->value, visited);
			}
		}
}

void Graph::DFS(int st)
{
	std::map<int, bool> visited;
	for (std::map<int, Node*>::iterator it = nodes.begin() ; it != nodes.end(); it++)
	{
		for (unsigned int i = 0; i < it->second->adjNodes.size() ; i++)
		{
			visited.insert(std::map<int, bool>::value_type(it->first, false));
		}
		DFSM(st, visited);
	}
}

void Graph::BellmanFord(int st)
{
	std::vector<int> distances;
	for (unsigned int i = 0 ; i < nodes.size() ; i++)
	{
		distances.push_back(maxC);
	}
	distances[st] = 0;

	for (unsigned int i = 0 ; i < nodes.size() ; i++)
	{
		for (unsigned int j = 0 ; j < nodes.at(i)->adjNodes.size() ; j++)
		{
			int src = nodes[i]->value;
			int dest = nodes.at(i)->adjNodes.at(j).second->value;
			int cost = nodes.at(i)->adjNodes.at(j).first;
			if (distances[src] != INT_MAX && distances[dest] > distances[src] + cost)
			{
				distances[dest] = distances[src] + cost;
			}
		}
	}

	std::cout << "Vertex,Shortest Distance" << std::endl;
	for (unsigned int c = 0 ; c < nodes.size() ; c++)
	{
		if (distances[c] == maxC) std::cout << c << ", NO PATH"<<std::endl;
		else std::cout << c << ", " << distances[c] << std::endl;
	}
}
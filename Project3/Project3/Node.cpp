#include "Node.h"


Node::Node() : value(-1) {}
Node::Node(int v) : value(v) {}

void Node::AddAdjNode(std::pair<int, Node*> info)
{
	adjNodes.push_back(info);
}
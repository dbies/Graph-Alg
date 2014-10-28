#include <vector>

class Node
{
private:
	
public:
	Node();
	Node(int);
	int value;
	void AddAdjNode(std::pair<int, Node*>);
	std::vector<std::pair<int, Node*>> adjNodes; 
};
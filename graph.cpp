#include <cstdio>
#include <climits>

#include <vector>
#include <map>

using namespace std;

struct Node;

typedef vector<Node *> NodeVec;

struct Node
{
	char data;
	NodeVec edges;
};

int numFnCalls = 0;

typedef map<Node *, int> DistMap;  // map of node to distance from final node
DistMap distMap;

int CalcShortestPathLength(Node *a, Node *b)
{
	numFnCalls++;
	if (a == b)
	{
		distMap[a] = 0;
		return 0;
	}
	else
	{
		int minLength = INT_MAX;
		for (NodeVec::iterator it = a->edges.begin(); it != a->edges.end(); it++)
		{
			Node *curNode = *it;
			if (distMap.find(curNode) != distMap.end())
			{
				// we have already calculated this distance
				printf("Reusing computation for %c\n", curNode->data);
				minLength = std::min(minLength, distMap[curNode]);
			}
			else
			{
				int calcDist = CalcShortestPathLength(curNode, b);
				distMap[curNode] = calcDist;
				minLength = std::min(minLength, calcDist);				
			}
		}

		int dist = INT_MAX;
		if (minLength < INT_MAX)
		{
			dist = 1 + minLength;
		}

		printf("Adding dist[%c]=%d\n", a->data, dist);
		distMap[a] = dist;
		return dist;
	}
}

Node *CreateNode(char c)
{
	Node *n = new Node;
	n->data = c;
	return n;
}

void AddChild(Node *n1, Node *n2)
{
	n1->edges.push_back(n2);
}

int main()
{
	// a --> b -> d
	//   \-> c -> e
	//		  \-> f
	Node *aNode = CreateNode('a');
	Node *bNode = CreateNode('b');
	Node *cNode = CreateNode('c');
	Node *dNode = CreateNode('d');
	Node *eNode = CreateNode('e');
	Node *fNode = CreateNode('f');

	AddChild(aNode, bNode);
	AddChild(aNode, cNode);
	AddChild(bNode, dNode);
	AddChild(cNode, eNode);
	AddChild(cNode, fNode);

	AddChild(bNode, cNode);

	printf("Shortest path=%d\n", CalcShortestPathLength(aNode, fNode));
	printf("Num calls to CalcShortestPathLength = %d\n", numFnCalls);
}
#include <cstdio>

#include <queue>
#include <stack>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

/*
void InorderTraversal(Node *root)
{
	if (!root) return;
	InorderTraversal(root->left);
	printf("%d\n", root->data);
	InorderTraversal(root->right);
}

void InorderTraversalNonRecursive(Node *root)
{
	Node *cur = root;
	std::stack<Node *> seenNodes;
	while (!done)
	{
		if (cur)
		{
			seenNodes.push(cur);
			cur = cur->left;
		}
		else if (!seenNodes.empty())
		{
			cur = seenNodes.pop();
			printf("%d ", cur->data);
			cur = cur->right;
		}

		if (!cur && seenNodes.empty())
		{
			done = true;
		}
	}
}

Node *DFS(Node *root, int searchVal)
{
	if (!root) return NULL;

	if (root->data == searchVal)
	{
		return root;
	}
	else
	{
		// search the left subtree
		Node *sub = DFS(root->left);
		if (sub) return sub;
		return DFS(root->right);
	}
}
*/

/*
Node *BreadthFirstTraversal(Node *root)
{
	//printf("(0) ");
	std::queue<Node *> nodesQ;
	if (root) nodesQ.push(root);
	//printf("(1) ");
	while (!nodesQ.empty())
	{
		root = nodesQ.front();

		if (root->left) nodesQ.push(root->left);
		if (root->right) nodesQ.push(root->right);

		//printf("elt=%d\n", elt);
		printf("%d ", root->data);
		//printf("(2) ");
		nodesQ.pop();
	}
}
*/

Node *BreadthFirstTraversal(Node *root)
{
	std::queue<Node *> nodesToTraverse;
	if (root) nodesToTraverse.push(root);

	while (!nodesToTraverse.empty())
	{
		root = nodesToTraverse.front();
		printf("%d ", root->data);

		if (root->left) nodesToTraverse.push(root->left);
		if (root->right) nodesToTraverse.push(root->right);

		nodesToTraverse.pop();
	}
}


// in-order: left, self, right
Node *DepthFirstTraversal(Node *root)
{
	std::stack<Node *> nodesToTraverse;
	bool done = false;
	while (!done)
	{
		if (root)
		{
			nodesToTraverse.push(root);
		}
		if (root->left)
		{
			root = root->left;
		}
		else
		{
			root = nodesToTraverse.top();
			printf("%d ", root->data);
			if (root->right) root = root->right;
			nodesToTraverse.pop();
		}
		if (!root && nodesToTraverse.empty())
		{
			done = true;
		}
	}
}


Node *CreateNode(int val, Node **parentPtr)
{
	Node *newNode = new Node;
	newNode->data = val;
	printf("Setting node val to %d\n", val);
	newNode->left = newNode->right = NULL;
	if (parentPtr) *parentPtr = newNode;
	return newNode;
}

Node *CreateTreeFromSortedArray(int *arr, int numElts, Node **parentPtr)
{
	if (!arr || !numElts) return NULL;

	// get the middle element of the array
	int middleIndex = numElts/2;
	Node *n = CreateNode(arr[middleIndex], parentPtr);

	// create a subtree from the left half of the array
	CreateTreeFromSortedArray(arr, numElts/2, &n->left);

	// create a subtree from the right half of the array
	if (middleIndex+1 < numElts)
	{
		CreateTreeFromSortedArray(arr+middleIndex+1, numElts/2, &n->right);
	}

	return n;
}

int MaxDepth(Node *root)
{
	if (!root) return 0;
	return 1 + std::max(MaxDepth(root->left), MaxDepth(root->right));
}

int MinDepth(Node *root)
{
	if (!root) return 0;
	return 1 + std::min(MinDepth(root->left), MinDepth(root->right));
}

bool IsBalanced(Node *root)
{
	return (MaxDepth(root)-MinDepth(root) <= 1);
}

typedef std::queue<Node *> tNodeQueue;
void CreateNodeListRecursive(tNodeQueue& nodeList, std::vector<tNodeQueue *>& lists)
{
	lists.push(nodeList);

	// all children
	tNodeQueue newList;
	typedef tNodeQueue::iterator nodeListIt;
	for (nodeListIt it = nodeList.begin(); it != nodeList.end(); it++)
	{
		Node *child = *it;
		newList.push(child);
	}
	CreateNodeListRecursive(newList, lists);
}

void CreateNodeList(Node *root)
{
	std::queue<Node *> nodeList;
	nodeList.push(root);

	std::vector<tNodeQueue> lists;
	CreateNodeListRecursive(nodeList, lists);
}

int main()
{
	/*
	Node *n1 = CreateNode(1, NULL);
	Node *root = n1;

	Node *n2 = CreateNode(2, &n1->left);
	CreateNode(4, &n2->left);
	CreateNode(5, &n2->right);

	n2 = CreateNode(3, &n1->right);
	CreateNode(6, &n2->left);
	n1 = CreateNode(7, &n2->right);
	CreateNode(8, &n1->left);

	printf("Before BFS\n");
	BreadthFirstTraversal(root);
	printf("Before DFS\n");
	DepthFirstTraversal(root);
	*/

	int arr[] = { 1, 2, 3 };
	Node *root = CreateTreeFromSortedArray(arr, sizeof(arr)/sizeof(arr[0]), NULL);
	BreadthFirstTraversal(root);
}
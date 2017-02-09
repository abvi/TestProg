struct Node {
	int val;
	vector<Node *> neighbors;
};

bool areConnected(Node *n1, Node *n2) {
	// do a breadth first search
	vector<Node *> nodesToScan;
	vector<Node *> visitedNodes;

	nodesToScan.push_back(n1);
	while (!nodesToScan.empty()) {
		Node *firstNode = nodesToScan.pop_front();
		if (firstNode == n2) {
			return true;
		}

		if (!visitedNodes.contains(firstNode)) {
			visitedNodes.push_back(firstNode);
			foreach (firstNode->neighbors as nbr) {
				nodesToScan.push_back(nbr);
			}			
		}
	}

	return false;
}

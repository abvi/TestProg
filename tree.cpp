struct Node {
	int val;
	Node *left;
	Node *right;
};

int maxDepth(Node *root, int depthSoFar) {
	if (!root) return depthSoFar;

	depthSoFar++;
	return max(maxDepth(root->left, depthSoFar), maxDepth(root->right, depthSoFar));
}

int minDepth(Node *root, int depthSoFar) {
	if (!root) return depthSoFar;

	depthSoFar++;
	return min(minDepth(root->left, depthSoFar), minDepth(root->right, depthSoFar));
}

bool isBalanced(Node *root) {
	return maxDepth(root, 1) - minDepth(root, 1) <= 1;
}

void createNodeListFromDepth(Node *root, int depth, vector<Node *> nodeLists[]) {
	if (!root) return;

	nodeLists[depth].push_back(root);
	depth++;
	createNodeListFromDepth(root->left, depth, nodeLists);
	createNodeListFromDepth(root->right, depth, nodeLists);
}

void createNodeLists(Node *root) {
	const int MAX_DEPTH = 100;
	vector<Node *> nodeLists[MAX_DEPTH];
	createNodeListFromDepth(root, 0, nodeLists);
}

Node *firstNode(Node *n) {
	if (n->left) {
		return firstNode(n->left);
	}
	return n;
}

Node *successor(Node *n) {
	if (n->right) {
		return firstNode(n->right);
	}

	if (n->parent->left == n) {
		// left child, so parent is the successor
		return n->parent;
	}
	else {
		return successor(n->parent);
	}
}

bool treeContains(Node *root, Node *n) {
	if (!root) return false;
	if (root == n) return true;
	return treeContains(node->left, n) || treeContains(node->right, n);
}

Node *commonAncestor(Node *root, Node *n1, Node *n2) {
	if (treeContains(root, n1) && treeContains(root, n2)) {
		return root;
	}

	Node *ancestor = commonAncestor(root->left, n1, n2);
	if (ancestor) return ancestor;

	ancestor = commonAncestor(root->right, n1, n2);
	if (ancestor) return ancestor;

	return NULL;
}
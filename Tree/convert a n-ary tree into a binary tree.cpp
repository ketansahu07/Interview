class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	
	TreeNode(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int data) {
		val = data;
	}

	Node(int data, vector<Node*> _children) {
		val = data;
		children = _children;
	}
};

class Codec {
public:
	TreeNode* encode(Node* root) {
		if(!root) return NULL;

		TreeNode *node = new TreeNode(root->val);
		if(root->children.size()) {
			node->left = encode(root->children[0]);
		}

		TreeNode *curr = node->left;
		for(int i=1; i<root->children.size(); i++) {
			curr->right = encode(root->children[i]);
			curr = curr->right;
		}

		return node;
	}

	Node* decode(TreeNode *root) {
		if(!root) return NULL;

		Node *node = new Node(root->val);
		TreeNode *curr = root->left;

		while(curr) {
			node->children.push_back(decode(curr));
			curr = curr->right;
		}

		return node;
	}
};
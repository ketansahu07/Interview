/*

Find the minimum time to burn a tree starting
from a leaf node.

Time Complexity: O(N)

*/

struct Node {
	int val;
	Node *left;
	Node *right;

	Node() {
		left = NULL;
		right = NULL;
	}
};

Node* newNode(int data) {
	Node *temp = new Node();
	temp->val = data;
	return temp;
}

struct Info {
	int lDepth;
	int rDepth;
	bool contains;
	int time;

	Info() {
		lDepth = rDepth = 0;
		contains = 0;
		time = -1;
	}
};

Info calcTime(Node *node, Info &info, int target, int &res) {
	if(!node) return info;

	if(!node->left && !node->right) {
		
		if(node->val == target) {
			info.contains = true;
			info.time = 0;
		}
		return info;
	}

	Info leftInfo;
	calcTime(node->left, leftInfo, target, res);

	Info rightInfo;
	calcTime(node->right, rightInfo, target, res);

	info.time = (node->left && leftInfo.contains) ? leftInfo.time + 1 : -1;

	if(info.time == -1) 
		info.time = (node->right && rightInfo.contains) ? rightInfo.time + 1 : -1;

	info.contains = (node->left && leftInfo.contains) || (node->right && rightInfo.contains);

	info.lDepth = (node->left) ? 1 + max(leftInfo.lDepth, leftInfo.rDepth) : 0;

	info.rDepth = (node->right) ? 1 + max(rightInfo.lDepth, rightInfo.rDepth) : 0;

	if(info.contains) {
		
		if(node->left && leftInfo.contains) {
			res = max(res, info.time + info.rDepth);
		}
		else if(node->right && rightInfo.contains) {
			res = max(res, info.time + info.lDepth);
		}
	} 

	return info;
}
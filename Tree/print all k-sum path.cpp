/*

Print all the k-sum path in a binary tree.
It can start at any node and end at any.

Time Complexity: O(N*H*H),
where N is number of nodes in binary tree
and H is the height of the binary tree.

*/

struct Node {
	int val;
	Node *left;
	Node *right;

	Node(int x) {
		val= x;
		left = NULL;
		right = NULL;
	}
};

void printVector(const vector<int>& v, int i)
{
  for (int j = i; j < v.size(); j++)
    cout << v[j] << " ";
  cout << endl;
}

void printKPathUtil(Node *root, vector<int> &path, int k) {
	if(!root) return;

	path.push_back(root->val);

	printKPathUtil(root->left, path, k);
	printKPathUtil(root->right, path, k);

	int sum = 0;
	for(int i=path.size()-1; i>=0; i--) {
		
		sum += path[i];

		if(sum == k) {
			printVector(path, i);
		}
	}

	path.pop_back();
}
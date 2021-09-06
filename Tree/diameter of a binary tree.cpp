/*

Find the dianmeter of a given binary tree 
i.e. the longest distance between any two nodes in the tree.

*/

int diameter(node* root, int* height) {
	// lh = height of left subtree 
	// rh = height of right subtree
	int lh = 0, rh = 0;

	// ldiameter = diameter of left subtree
	// rdiameter = deameter of right subtree
	int ldiameter = 0, rdiameter = 0;

	if(root == NULL) {
		*height = 0;
		return 0; // diameter is also 0
	}

	// Get the heights of left and right subtrees in lh and rh
	// and store the rturned values in ldiameter and rdiameter
	ldiameter = diameter(root->left, &lh);
	rdiameter = diameter(root->right, &rh);

	// Height of current node is max of heights of left and 
	// right subtrees plus 1
	*height = max(lh, rh) + 1;

	return max(lh + rh + 1, max(ldiameter, rdiameter));
}
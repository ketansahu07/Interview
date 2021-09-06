/*
Lowest common ancestor in binary tree.
Assuming both the key exists in the tree.
*/

Node* findLCA(Node* root, int n1, int n2) {
	// Base case
	if(root == NULL) return NULL;

	// if either n1 or n2 matches with root's key, report
	// the presence by returning root
	if(root->key == n1 || root->key == n2)
		return root;

	// Look for keys in left and right subtrees
	Node *left_lca = findLCA(root->left, n1, n2);
	Node *right_lca = findLCA(root->right, n1, n2);

	// if both of the above calls return Non-NULL, then one key 
	// is present in one subtree and other is present in other,
	// So this node is the LCA
	if(left_lca && right_lca) return root;

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}
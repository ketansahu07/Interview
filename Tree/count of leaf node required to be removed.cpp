/*

Count of leaf node required to be removed to empty a given binary tree.

Time Complexity: O(N), where N is the number of nodes in the tree.

*/

int maxHeightToLeafUTIL(Node* curr, map<int, vector<int> >& mp)
{
    if (curr == NULL) {
        return 0;
    }
 
    int leftLeaf = maxHeightToLeafUTIL(curr->left, mp);
 
    int rightLeaf = maxHeightToLeafUTIL(curr->right, mp);
 
    int maxHeightSubtree = 1 + max(leftLeaf, rightLeaf);
 
    mp[maxHeightSubtree].push_back(curr->data);
 
    return maxHeightSubtree;
}

void printAndDelete(Node* root)
{
 
    // Stores the leaf deletion with
    // each iterationd
    map<int, vector<int> > mp;
 
    maxHeightToLeafUTIL(root, mp);
 
    for (auto step : mp) {
 
        cout << mp[step.first].size() << " ";
    }
}
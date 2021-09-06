/**
 * The idea is to store in reverse order in vector while storing the elements of even level.
 **/


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    
    queue<TreeNode*> q;
    vector<vector<int>> out;
        
    q.push(root);  
    int level = 0; /* to alternate levels, or a bool variable */
    
    while (!q.empty()) {
        
        int sz = q.size();  
        vector<int> curr(sz); 
        
        for (int i = 0; i < sz; i++) {
            
            TreeNode* tmp = q.front();
            q.pop();
            
            if (level == 0) {
                curr[i] = tmp->val; // odd level, insert like 0, 1, 2, 3 etc. 
            } else {
                curr[sz - 1 - i] = tmp->val; /* even level insert from end. 3, 2, 1, 0. (sz - i - 1) to get the index from end */
            }
            
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        out.push_back(curr); // now push the level traversed to output vector
        level = !level; // toggle the level using negation. or level == 0 ? level = 1 : level = 0;
    }
    return out;
}
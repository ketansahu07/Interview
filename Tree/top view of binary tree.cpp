void topView(struct Node *root)
{
    //Your code here
    if(!root) return;
    
    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;
    int hd = 0;
    q.push(make_pair(root,hd));
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* node = temp.first;
        hd = temp.second;
        m[hd].push_back(node->data);
        if(node->left)
            q.push(make_pair(node->left,hd-1));
        if(node->right)
            q.push(make_pair(node->right,hd+1));
    }
    
    map<int, vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->second[0]<<" ";
    }
}
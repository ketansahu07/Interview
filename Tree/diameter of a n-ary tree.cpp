struct Node
{
    char key;
    vector<Node *> child;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}

// ===================================================
// Time complexity is more.
// But this is the base for the optimized solution.

int depthOfTree(struct Node *ptr)
{
    // Base case
    if (!ptr)
        return 0;
 
    int maxdepth = 0;
 
    // Check for all children and find
    // the maximum depth
    for (vector<Node*>::iterator it = ptr->child.begin();
                           it != ptr->child.end(); it++)
 
        maxdepth = max(maxdepth , depthOfTree(*it));
 
    return maxdepth + 1;
}

int diameter(struct Node *ptr)
{
    // Base case
    if (!ptr)
        return 0;
 
    // Find top two highest children
    int max1 = 0, max2 = 0;
    for (vector<Node*>::iterator it = ptr->child.begin();
                          it != ptr->child.end(); it++)
    {
        int h = depthOfTree(*it);
        if (h > max1)
           max2 = max1, max1 = h;
        else if (h > max2)
           max2 = h;
    }
 
    // Iterate over each child for diameter
    int maxChildDia = 0;
    for (vector<Node*>::iterator it = ptr->child.begin();
                           it != ptr->child.end(); it++)
        maxChildDia = max(maxChildDia, diameter(*it));
 
    return max(maxChildDia, max1 + max2 + 1);
}

// ===================================================
// Optimized solution

int diameter(struct Node *ptr,int &diameter_of_tree)
{
    // Base case
    if (!ptr)
        return 0;
 
    // Find top two highest children
    int max1 = 0, max2 = 0;
    for (vector<Node*>::iterator it = ptr->child.begin();it != ptr->child.end(); it++)
    {
        int h = diameter(*it,diameter_of_tree);
        if (h > max1)
        max2 = max1, max1 = h;
        else if (h > max2)
        max2 = h;
    }
 
    // Find whether our node can be part of diameter
    diameter_of_tree = max(max1 + max2 + 1,diameter_of_tree);
 
    return max(max1,max2) + 1;
}

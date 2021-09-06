/*

Find if an array of strings can be chained to 
form a circle.

We’ll check two conditions: 

1. Indegree and Outdegree of each vertex should be the same.

2. The graph should be strongly connected.

*/

#define M 26

void dfs(vector<int> g[], int u, vector<bool> &visit)
{
    visit[u] = true;
    for (int i = 0; i < g[u].size(); ++i)
        if(!visit[g[u][i]])
            dfs(g, g[u][i], visit);
}

bool isConnected(vector<int> g[], vector<bool> &mark, int s)
{
    vector<bool> visit(M, false);
 
    dfs(g, s, visit);
 
    //    now loop through all characters
    for (int i = 0; i < M; i++)
    {

        if (mark[i] && !visit[i])
            return false;
    }
 
    // If we reach that means graph is connected
    return true;
}

bool possibleOrderAmongString(string arr[], int N)
{
    // Create an empty graph
    vector<int> g[M];
 
    // Initialize all vertices as not marked
    vector<bool> mark(M, false);
 
    // Initialize indegree and outdegree as 0.
    vector<int> in(M, 0), out(M, 0);
 
    // Process all strings one by one
    for (int i = 0; i < N; i++)
    {
        // Find first and last characters
        int f = arr[i].front() - 'a';
        int l = arr[i].back() - 'a';
 
        // Mark the characters
        mark[f] = mark[l] = true;
 
        // increase indegree and outdegree count
        in[l]++;
        out[f]++;
 
        // Add an edge in graph
        g[f].push_back(l);
    }
 
    // If for any character indegree is not equal to
    // outdegree then ordering is not possible
    for (int i = 0; i < M; i++)
        if (in[i] != out[i])
            return false;
 
    return isConnected(g, mark, arr[0].front() - 'a');
}
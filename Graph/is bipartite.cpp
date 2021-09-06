/*

Check if a given graph is bipartite of not.

Time Complexity: O(V + E)

*/

bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {

        int u = q.front();
        q.pop();
 
        // Return false if there is a self-loop
        if (G[u][u] == 1)
            return false;
 
        for (int v = 0; v < V; ++v) {

            if (G[u][v] && colorArr[v] == -1) {

                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}

bool isBipartite(int G[][V])
{

    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
 
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;
 
    return true;
}
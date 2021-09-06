/*

Two methods:

1. Backtracking O(m^V)

2. BFS O(V + E)

*/

// ============================================
// Backtracking solution starts here
// ============================================

bool isSafe(int v, bool graph[V][V],
            int color[], int c)
{
    for(int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
             
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m,
                       int color[], int v)
{
     
    /* base case: If all vertices are
       assigned a color then return true */
    if (v == V)
        return true;
 
    for(int c = 1; c <= m; c++)
    {
         
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
 
            if (graphColoringUtil(graph, m, color, v + 1) == true)
                return true;
 
            color[v] = 0;
        }
    }
 
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
     
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;
 
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
 
    printSolution(color);
    return true;
}

// ============================================
// BFS solution starts here
// ============================================

class node
{
 
    // A node class which stores the color and the edges
    // connected to the node
public:
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node>& nodes, int n, int m)
{
 
    vector<int> visited(n + 1, 0);
 
    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;
 
    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++)
    {
 
        if (visited[sv])
            continue;
 
        visited[sv] = 1;

        queue<int> q;
        q.push(sv);
 
        // BFS Travel starts here
        while (!q.empty())
        {
 
            int top = q.front();
            q.pop();
 
            // Checking all adjacent nodes
            // to "top" edge in our queue
            for (auto it = nodes[top].edges.begin(); it != nodes[top].edges.end(); it++)
            {
 
                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;
 
                // If number of colors used shoots m, return
                // 0
                maxColors
                    = max(maxColors, max(nodes[top].color,
                                         nodes[*it].color));
                if (maxColors > m)
                    return 0;
 
                // If the adjacent node is not visited,
                // mark it visited and push it in queue
                if (!visited[*it]) {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }
 
    return 1;
}

void solve() {
	vector<node> nodes(n + 1);
 
  	// Add edges to each node as per given input
	for (int i = 0; i < n; i++)
	{
		for(int j =0;j<n;j++)
		{
			if(graph[i][j]) // assume a graph exist
			{
		  		// Connect the undirected graph
		  		nodes[i].edges.insert(j);
		  		nodes[j].edges.insert(i);
			}
		}	
	}

	canPaint(nodes, n, m)
}
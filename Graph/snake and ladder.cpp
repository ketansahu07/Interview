struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};

int getMinDiceThrows(int move[], int N)
{
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<queueEntry> q;

    visited[0] = true;      // Mark node 0 as visited
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0
    q.push(s);              // Enqueue 0'th vertex

    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        q.pop();
        
        int v = qe.v;
 
        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;

        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            if (!visited[j])
            {
                
                visited[j] = true;

                queueEntry a;
                a.dist = (qe.dist + 1);
 
                // Check if there a snake or ladder at 'j'
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;

                q.push(a);
            }
        }
    }
    return qe.dist;
}
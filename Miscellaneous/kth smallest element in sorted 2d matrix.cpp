/*

Find the Kth smallest element in row wise and col wise
sorted 2D matrix.

Uses min heap.

Here Lambda function is used inplace of custom comparator
for in-built heap.

Time Complexity: O(N) + O(Klog(N))

Alternate way is to use binary search. (Greater Time Complexity)

*/

int kthSmallest(int mat[4][4], int n, int k)
{
    // USING LAMBDA FUNCTION
    // [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH
    // ARE OUT OF SCOPE i.e. mat[r]
    // NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
      // Capturing the value of mat by reference to prevent copying
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
     
    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }
     
    //RUNNING LOOP FOR (k-1) TIMES
    for(int i=1; i<k; i++){
        auto p = pq.top();
        pq.pop();
         
        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if(p.second+1 < n) pq.push({p.first,p.second + 1});
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}
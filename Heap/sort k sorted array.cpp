/*


Given an array of n elements, where each element 
is at most k away from its target position, 
devise an algorithm that sorts in O(n log k) time.

Time Complexity: O(Nlog(K))

*/

int sortK(int arr[], int n, int k)
{

    //(A O(k) operation). We assume, k < n.
    int size;
    size=(n==k)?k:k+1;

    priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
}
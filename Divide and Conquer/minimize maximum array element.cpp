/*

Minimize maximum array element possible by at most K splits on the given array.

Time Complexity: O(N*log(K))

*/

// Function to check if all array
// elements can be reduced to at
// most mid by at most K splits
int possible(int A[], int N,
             int mid, int K)
{
    // Stores the number
    // of splits required
    int count = 0;
 
    // Traverse the array arr[]
    for (int i = 0; i < N; i++) {
 
        // Update count
        count += (A[i] - 1) / mid;
    }
 
    // If possible, return true.
    // Otherwise return false
    return count <= K;
}

// Function to find the minimum possible
// value of maximum array element that
// can be obtained by at most K splits
int minimumMaximum(int A[], int N, int K)
{
    // Set lower and upper limits
    int lo = 1;
    int hi = *max_element(A, A + N);
    int mid;
 
    // Perform Binary Search
    while (lo < hi) {
 
        // Calculate mid
        mid = (lo + hi) / 2;
 
        // Check if all array elements
        // can be reduced to at most
        // mid value by at most K splits
        if (possible(A, N, mid, K)) {
 
            // Update the value of hi
            hi = mid;
        }
 
        // Otherwise
        else {
 
            // Update the value of lo
            lo = mid + 1;
        }
    }
 
    // Return the minimized maximum
    // element in the array
    return hi;
}
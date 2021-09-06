/*

Time Complexity: O(N)

*/

int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {

            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
int longestAlternatingSubsequence(int arr[], int n)
{
     
    /*las[i][0] = Length of the longest
        alternating subsequence ending at
        index i and last element is greater
        than its previous element
    las[i][1] = Length of the longest
        alternating subsequence ending
        at index i and last element is
        smaller than its previous element */
    int las[n][2];
  
    for(int i = 0; i < n; i++)
        las[i][0] = las[i][1] = 1;
     
    int res = 1;
  
    // Compute values in bottom up manner
    for(int i = 1; i < n; i++)
    {
        
        for(int j = 0; j < i; j++)
        {
             
            if (arr[j] < arr[i] && las[i][0] < las[j][1] + 1)
                las[i][0] = las[j][1] + 1;
  
            if(arr[j] > arr[i] && las[i][1] < las[j][0] + 1)
                las[i][1] = las[j][0] + 1;
        }
  
        // Pick maximum of both values at index i
        if (res < max(las[i][0], las[i][1]))
            res = max(las[i][0], las[i][1]);
    }
    return res;
}
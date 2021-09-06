/**
 * Longest Common Prefix in given array of words.
 * 
 * Take the character of the smallest string and check for that in every other word if ther match. 
 * 
 * Time Complexity: O(N*M)
 * N is the number of string and M is the length of the largest string
 */

// A Function to find the string having the minimum
// length and returns that length
int findMinLength(string arr[], int n)
{
    int min = arr[0].length();
 
    for (int i=1; i<n; i++)
        if (arr[i].length() < min)
            min = arr[i].length();
 
    return(min);
}
 
// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix(string arr[], int n)
{
    int minlen = findMinLength(arr, n);
 
    string result; // Our resultant string
    char current;  // The current character
 
    for (int i=0; i<minlen; i++)
    {
        // Current character (must be same
        // in all strings to be a part of
        // result)
        current = arr[0][i];
 
        for (int j=1 ; j<n; j++)
            if (arr[j][i] != current)
                return result;
 
        // Append to result
        result.push_back(current);
    }
 
    return (result);
}
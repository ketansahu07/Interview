/*

Find if there is a rectangle in a binary matrix.

Time Complexity: O(M*N + P*P*log(P*P)), where P = max(M, N)

*/

 bool searchForRectangle(int rows, int cols,
                        vector<vector<int>> mat)
{
    // Make sure that matrix is non-trivial
    if (rows < 2 || cols < 2)
    {
        return false;
    }
 
	int num_of_keys;
    map<int, vector<int>> adjsList;
    
    if (rows >= cols)
    {
        // Row-wise
        num_of_keys = rows;
         
        // Convert each row into vector of col indexes
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j])
                {
                    adjsList[i].push_back(j);
                }
            }
        }
    }
     
    else
    {
        // Col-wise
        num_of_keys = cols;
         
        // Convert each col into vector of row indexes
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j])
                {
                    adjsList[j].push_back(i);
                }
            }
        }
    }
 
    // Search for a rectangle whose four corners are 1's
    map<pair<int, int>, int> pairs;
    for (int i = 0; i < num_of_keys; i++)
    {
        vector<int> values = adjsList[i];
        int size = values.size();
        for (int j = 0; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                pair<int, int> temp
                        = make_pair(values[j],
                                     values[k]);
                if (pairs.find(temp)
                    != pairs.end())
                {
                    return true;
                } else {
                    pairs[temp] = i;
                }
            }
        }
    }
    return false;
}
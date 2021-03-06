int MatrixChainOrder(int p[], int n)
{
 
    /*0th row and 0th
    column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + 
                    m[k + 1][j] + 
                    p[i - 1] * p[k] * p[j];
                
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n - 1];
}
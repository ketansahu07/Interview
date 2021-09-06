/*

Find the pair of elements swapping which makes
the sum of two array same.

Time Complexity: O(M*N)
later improved to O(M + N)

*/

/*

We are looking for two values, a and b, such that: 
sumA - a + b = sumB - b + a
    2a - 2b  = sumA - sumB
      a - b  = (sumA - sumB) / 2

*/

int getSum(int X[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += X[i];
    return sum;
}

int getTarget(int A[], int n, int B[], int m)
{
    // Calculation of sums from both arrays
    int sum1 = getSum(A, n);
    int sum2 = getSum(B, m);
 
    // because that the target must be an integer
    if ((sum1 - sum2) % 2 != 0)
        return 0;
    return ((sum1 - sum2) / 2);
}

void findSwapValues(int A[], int n, int B[], int m)
{
    int target = getTarget(A, n, B, m);
    if (target == 0)
        return;
 
    // Look for val1 and val2, such that
    // val1 - val2 = (sumA - sumB) / 2
    int val1, val2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] - B[j] == target) {
                val1 = A[i];
                val2 = B[j];
            }
        }
    }
 
    cout << val1 << " " << val2;
}

/*

Aassume array1 is small i.e. (m < n)
where m is array1.length and n is array2.length

1. Find sum1(sum of small array elements) ans sum2
  (sum of larger array elements). // time O(m+n)

2. Make a hashset for small array(here array1).

3. Calculate diff as (sum1-sum2)/2.

4. Run a loop for array2
     for (int i equal to 0 to n-1)
       if (hashset contains (array2[i]+diff))
           print array2[i]+diff and array2[i]
           set flag  and break;

5. If flag is unset then there is no such kind of 
pair.

*/
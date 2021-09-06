struct Job
{
    int start, finish, profit;
};

bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

int findMaxProfit(Job arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr+n, jobComparataor);
 
    // dp job table
    int *table = new int[n];

    table[0] = arr[0].profit;
 
    for (int i=1; i<n; i++)
    {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
 
        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);   // table[i-1] (excluding condition)
    }
 
    int result = table[n-1];

    delete[] table;
 
    return result;
}
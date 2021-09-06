/*

Fisher-Yates Algorithm.

*/

void randomize (int arr[], int n)
{
    srand (time(0));
 
    // Start from the last element and swap
    // one by one. We don't need to run for
    // the first element that's why i > 0
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
 
        swap(&arr[i], &arr[j]);
    }
}

// =============================================
// From start index to end
// =============================================

void shuffle(int arr[], int n)
{
	srand (time(0));

    // read array from the lowest index to highest
    for (int i = 0; i <= n - 2; i++)
    {
        // generate a random number `j` such that `i <= j < n`
        int j = i + rand() % (n - i);
 
        // swap the current element with the randomly generated index
        swap(&arr[i], &arr[j]);
    }
}
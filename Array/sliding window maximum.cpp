/**
 * Find maximum in every window of size k.
 * 
 * Logic:
 * 	Create a deque to store k elements.
	
	Run a loop and insert first k elements in the deque. 
	Before inserting the element, check if the element at 
	the back of the queue is smaller than the current element, 
	if it is so remove the element from the back of the deque, 
	until all elements left in the deque are greater than the current element. 
	Then insert the current element, at the back of the deque.
	
	Now, run a loop from k to end of the array.
	
	Print the front element of the deque.
	
	Remove the element from the front of the queue if they are out of the current window.
	
	Insert the next element in the deque. Before inserting the element, 
	check if the element at the back of the queue is smaller than the 
	current element, if it is so remove the element from the back of 
	the deque, until all elements left in the deque are greater than 
	the current element. Then insert the current element, at the back of the deque.
	
	Print the maximum element of the last window.
 */

void printKMax(int arr[], int n, int k)
{
     
    deque<int> Qi(k);
 
    /* Process first k (or first window)
     elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
     
    	// removing smaller elements from rear
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        Qi.push_back(i);
    }
 
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
     
    	// print the largest element of previous window
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
 
        // removing smaller elements from rear
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    cout << arr[Qi.front()];
}
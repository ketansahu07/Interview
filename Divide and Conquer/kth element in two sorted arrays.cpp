/**
 * Find the kth element in two sorted arrays.
 * 
 * In below algorithm arr1 is starting of array 1 and end1 is ending of array 1
 */

int kth(int *arr1, int *arr2, int *end1, int *end2, int k) {
	if(arr1 == end1)
		return arr2[k];	// return kth element from arr2

	if(arr2 == end2)
		return arr1[k]; // return kth element from arr1

	int mid1 = (end1 - arr1) / 2;
	int mid2 = (end2 - arr2) / 2;

	if(mid1 + mid2 < k) {
		// since mid1 + mid2 < k, we need to include more elements

		if(arr1[mid1] > arr2[mid2])	// since arr2[mid2] is smaller we shift mid2 and reduce k
									// to make the search space smaller but still including more elements to reach k
			return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);

		else		// since arr1[mid1] is smaller we shift mid1 for the same reason as above and reduce k
			return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
	}
	else {
		// since mid1 + mid2 exceed k we need to exclude some of the elements from the current set of elements.

		if(arr1[mid1] > arr2[mid2])
			return kth(arr1, arr2, arr1 + mid1, end2, k);
		else
			return kth(arr1, arr2, end1, arr2 + mid2, k);
	}
}
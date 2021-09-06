/**
 * Find the median of two sorted array of different sizes.
 */

double median(vector<int> &A, vector<int> &B) {
	int n = A.size();
	int m = B.size();

	if(n > m) return median(B, A);

	int start = 0;
	int end = n;
	int realMidInMergedArray = (n + m + 1)/2;

	while(start <= end) {
		int mid = (start + end) / 2;
		int leftAsize = mid;
		int leftBsize = realMidInMergedArray - mid;
		int leftA = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN;
		int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
		int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
		int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;

		if(leftA <= rightB && leftB <= rightA) {
			if((m + n) % 2 == 0)	// if the number of elements are even
				return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
			else					// if the number of elements are odd
				return max(leftA, leftB);
		}
		else if(leftA > rightB) {	// if the largest element in the left of A is greater than right of B
			end = mid - 1;			// then shift the mid to left as that will reduce the largest in left of A
		}
		else {						// if the largest element in the left of B is greater than right of A
			start = mid + 1;		// then shift tht mid to the right as that will reduce the largest in B
		}
	}
	return 0.0;
}
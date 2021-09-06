/**
 * Given a certain number of cows we need to place them in rows such that the minimum distance between them is largest.
 * An array of positions is given.
 * 
 * Since we need to check for each of the min distance starting from 1 to (arr[n-1] - arr[0]), it represents a monotonic
 * increase in the dist considered. Thus we can apply Binary search here. 
 */


bool isPossible(int arr[], int n, int cows, int curr_min) {
	int cowsCount = 1;
	int lastPlacedCow = arr[0];

	for(int i=1; i<n; i++) {
		if(arr[i] - lastPlacedCow >= curr_min) {
			cowsCount++;
			lastPlacedCow = arr[i];
		}

		if(cowsCount >= cnt) return true;
	}

	return false;
}

int placeCows(int arr[], int n, int cows) {
	sort(arr, arr+n);

	int low = 1, high = arr[n-1] - arr[0];
	int result = INT_MIN;
	
	while(low <= high) {
		int mid = (low + high) / 2;

		if(isPossible(arr, n, cows, mid)) {
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return result;
}
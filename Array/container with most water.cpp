/*

Find the container with most water in the given array.

Time Complexity: O(N)

*/

int maxArea(int arr[], int len) {
	int left = 0;
	int right = len-1;
	int area = 0;
	int res = 0;

	while(left < right) {
		
		area = min(arr[left], arr[right]) * (right - left);
		if(res < area) 
			res = area;

		if(arr[left] < arr[right])
			left++;
		else
			right--;
	}
	return res;
}
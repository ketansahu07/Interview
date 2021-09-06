/**
 * Allocate the number of pages to a given number of students
 * such that the maximum number of pages assigned to a student
 * is minimum.
 * 
 * All the pages from one book should be assigned to one student only.
 * 
 * The logic is to apply binary search in the sample space between the minimum no.of pages
 * and the total no.of pages of all the books. Find the mid of the sample space and assume
 * that as the minimum no.of pages that a student can have and if possible with current min
 * then try with even smaller value else try with a larger value.
 */

bool isPossible(int arr[], int n, int m, int curr_min) {
	int studentsRequired = 1;
	int curr_min = 0;

	// iterate over all the books
	for(int i=0; i<n; i++) {
		// if the no.of pages in the current book is greater than curr_min
		// then this min is not possible
		if(arr[i] > curr_min) 
			return false;

		// if pages sum plus pages from current book exceed the curr_min
		// then this book shoudl be assigned to the next student
		if(curr_sum + arr[i] > curr_min) {
			studentsRequired++;

			// curr_sum for this new student will start form the no.of pages
			// of this current book 
			curr_sum = arr[i];

			// student required shoudl not exceed the no.of given student
			if(studentsRequired > m)
				return false;
		}
		else	// else assign the current no.of pages to the current student;
			curr_sum += arr[i];
	}

	return true;
}

int findPages(int arr[], int n, int m) {
	long sum = 0;

	// return -1 if no.of books is less than no.of students
	if(n < m)
		return -1;

	// count total number of pages
	for(int i=0; i<n; i++)
		sum += arr[i];

	// initialize start as 0 and end as total pages
	int start = 0; // can also be set to the min no.of pages in the array
	int end = sum;
	int result = INT_MAX;

	while(start <= end) {
		// check if it is possible to distribute books
		// by using mid as the current minimum no.of pages
		int mid = (start + end) / 2;

		if(isPossible(arr, n, m, mid)) {
			// this could be the result so save it
			result = mid;

			// then try for even lesser value of min
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return result;
}
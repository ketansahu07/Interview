/**
Find the Kth permutation of first n digits.

*/

class Solution{
public:
	string getPermutation(int n, int k) {
		int fact = 1;
		vector<int> numbers;
		for(int i=1; i<n; i++) {
			fact = fact * i;
			numbers.push_back(i);
		}
		numbers.push_back(n);	// entering the last number

		string ans = "";
		k = k - 1;	// subtrating for zero based indexing

		while(true) {
			ans = ans + to_string(numbers[k / fact]);	// (k/fact) gives the index of the number from which the permutation will start for this particular position in the string
			numbers.erase(numbers.begin() + k / fact);	// removing that number coz that number is included in the permutation now
			if(numbers.size()==0) {
				break;
			}
			k = k % fact;	// new k for remaining numbers in the array
			fact = fact / numbers.size();	// since a number is removed from the array so the number of arrangements of the remaining number reduces
		}

		return ans;
	}	
};
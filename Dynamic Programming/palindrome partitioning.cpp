/**
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.
Determine the fewest cuts needed for a palindrome partitioning of a given string.

Logic:

// i is the starting index and j is the ending index. i must be passed as 0 and j as n-1

minPalPartion(str, i, j) = 0 if i == j. // When string is of length 1.
minPalPartion(str, i, j) = 0 if str[i..j] is palindrome.

// If none of the above conditions is true, then minPalPartion(str, i, j) can be 
// calculated recursively using the following formula.

minPalPartion(str, i, j) = Min { minPalPartion(str, i, k) + 1 + minPalPartion(str, k+1, j) } //where k varies from i to j-1 and 1 is added for the current partition

*/
=============================================================================================

#include <bits/stdc++.h>
using namespace std;

// Returns the minimum number of cuts
// needed to partition a string
// such that every part is a palindrome
int minPalPartion(string str)
{
	// Get the length of the string
	int n = str.length();

	/* Create two arrays to build the solution
	in bottom up manner
	C[i][j] = Minimum number of cuts needed for
			palindrome partitioning
			of substring str[i..j]
	P[i][j] = true if substring str[i..j] is
			palindrome, else false
	Note that C[i][j] is 0 if P[i][j] is true */
	int C[n][n];
	bool P[n][n];

	// Every substring of length 1 is a palindrome
	for (int i = 0; i < n; i++) {
		P[i][i] = true;
		C[i][i] = 0;
	}

	/* L is substring length. Build the
	solution in bottom up manner by
	considering all substrings of
	length starting from 2 to n.
	The loop structure is same as Matrix
	Chain Multiplication problem
	( See https:// www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/ )*/
	for (int L = 2; L <= n; L++) {

		// For substring of length L, set
		// different possible starting indexes
		for (int i = 0; i < n - L + 1; i++) {
			int j = i + L - 1; // Set ending index

			// If L is 2, then we just need to
			// compare two characters. Else
			// need to check two corner characters
			// and value of P[i+1][j-1]
			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

			// IF str[i..j] is palindrome, then C[i][j] is 0
			if (P[i][j] == true)
				C[i][j] = 0;
			else {

				// Make a cut at every possible
				// location starting from i to j,
				// and get the minimum cost cut.
				C[i][j] = INT_MAX;
				for (int k = i; k <= j - 1; k++)
					C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
			}
		}
	}

	// Return the min cut value for
	// complete string. i.e., str[0..n-1]
	return C[0][n - 1];
}

// Driver code
int main()
{
	string str = "ababbbabbababa";
	cout << "Min cuts needed for Palindrome"
			" Partitioning is "
		<< minPalPartion(str);
	return 0;
}

==================================================================================================

// If we find all palindromic substring 1st and then we calculate minimum cut, time complexity will reduce to O(n2). 

#include <limits.h>
#include <stdio.h>
#include <string.h>

// A utility function to get minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Returns the minimum number of cuts needed to partition a string
// such that every part is a palindrome
int minPalPartion(char* str)
{
	// Get the length of the string
	int n = strlen(str);

	/* Create two arrays to build the solution in bottom-up manner
	C[i] = Minimum number of cuts needed for a palindrome partitioning
				of substring str[0..i]
	P[i][j] = true if substring str[i..j] is palindrome, else false
	Note that C[i] is 0 if P[0][i] is true */
	int C[n];
	bool P[n][n];

	int i, j, k, L; // different looping variables

	// Every substring of length 1 is a palindrome
	for (i = 0; i < n; i++) {
		P[i][i] = true;
	}

	/* L is substring length. Build the solution in bottom up manner by
	considering all substrings of length starting from 2 to n. */
	for (L = 2; L <= n; L++) {
		// For substring of length L, set different possible starting indexes
		for (i = 0; i < n - L + 1; i++) {
			j = i + L - 1; // Set ending index

			// If L is 2, then we just need to compare two characters. Else
			// need to check two corner characters and value of P[i+1][j-1]
			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
		}
	}

	for (i = 0; i < n; i++) {
		if (P[0][i] == true)
			C[i] = 0;
		else {
			C[i] = INT_MAX;
			for (j = 0; j < i; j++) {
				if (P[j + 1][i] == true && 1 + C[j] < C[i])	// if (j + 1) to i is a palindrom and sum of partitions till C[j] and 1 (current partition) is less than C[i] 
					C[i] = 1 + C[j];
			}
		}
	}

	// Return the min cut value for complete string. i.e., str[0..n-1]
	return C[n - 1];
}

// Driver program to test above function
int main()
{
	char str[] = "ababbbabbababa";
	printf("Min cuts needed for Palindrome Partitioning is %d",
		minPalPartion(str));
	return 0;
}

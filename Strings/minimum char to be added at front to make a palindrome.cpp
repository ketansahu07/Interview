/**
 * First we concat string by concatenating given string, 
 * a special character and reverse of given string then we will get lps array for this concatenated string.
 * 
 * Here we are only interested in the last value of this lps array because it shows us the largest suffix 
 * of the reversed string that matches the prefix of the original string i.e these many characters already 
 * satisfy the palindrome property. Finally minimum number of character needed to make the string 
 * a palindrome is length of the input string minus last entry of our lps array.
 */


int computeLPSArray(string str) {
	int M = str.length();
	vector<int> lps(M);

	int len = 0;
	lps[0] = 0;

	int i = 1;
	while(i < M) {
		if(str[i] == str[len]) {
			len++;
			lps[i] = len;
			i++; 
		}
		else {
			if(len > 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps.back();
}

int getMinCharToAddedToMakeStringPalin(string str) {
	string revStr = str;
	reverse(revStr.begin(), revStr.end());

	// Get concatenation of string, special character
    // and reverse string
	string concat = str + "$" + revStr;

	//  Get LPS array of this concatenated string
	int lps = computeLPSArray(concat);

	return str.length() - lps;
}
/**
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input:  s = "applepenapple", wordDict = ["apple","pen"]
Output: true

Time complexity: O(2^n)

*/


class Solution {
    bool dfs(string s, unordered_set<string> &hash, unordered_map<string, bool> &dp) {
        if(s.length()==0) return true;  // Empty string exists in the dictionary
        
        if(dp.find(s)!=dp.end()) return dp[s];
        
        int len = s.length();
        
        for(int i=1; i<=len; i++) {
            string first_half = s.substr(0, i);
            string second_half = s.substr(i);
            
            if(hash.find(first_half)!=hash.end() && dfs(second_half, hash, dp)) {
                dp[s] = true;
                return true;
            }
        }
        
        dp[s] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        int len = s.length();
        
        for(string s:wordDict) {
            hash.insert(s);
        }
        
        unordered_map<string, bool> dp;
        
        return dfs(s, hash, dp);
    }
};
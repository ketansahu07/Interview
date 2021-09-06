/*

Time Complexity: O(N)

*/


bool isPossible(vector<int>& nums) {
    // count the frequency of a value and store with unordered_map<value, freq>
    unordered_map<int, int> freq;
    for (auto it : nums) 
        freq[it]++;
    
    //store the # of sequences requiring a value with unordered_map<value, freq>
    unordered_map<int, int> seq;
    for (auto it : nums) {
        // if the value is completely used in one or more sequences
        if (freq[it] == 0) 
            continue;
        
        // if the value is needed by some sequence with a smaller value at the end
        if (seq[it] > 0) {
            // use the value in one sequence that needs it
            seq[it]--;
            // the next value will be needed by that sequence
            seq[it+1]++;
        } 
        // if this element is not needed by any sequence with a smaller values 
        // (since the element might not be consecutive),
        // check if the 2 larger values after it can be connected to start a new seq
        else if (freq[it + 1] > 0 && freq[it + 2] > 0) {
            freq[it+1]--;
            freq[it+2]--;
            seq[it+3]++;
        }
        // the larger values after it cannot be connected 
        else 
            return false;
        
        // decrease the count of used element
        freq[it]--;
    }
    return true; 
}

// ==========================================================================
// A solution with greater time complexity but less space complexity
// ==========================================================================

bool isPossible(vector<int>& nums) {
      unordered_map <int, int> m;
      int n = nums.size();
      for(int i = 0; i < n; i++){
         m[nums[i]]++;
      }
      int cnt = n;
      for(int i = 0; i < n; i++){
         int x = nums[i];
         if(m[x] && m[x + 1] && m[x + 2]){
            m[x]--;
            m[x + 1]--;
            m[x + 2]--;
            x += 3;
            cnt -= 3;
            while(m[x] > 0 && m[x] > m[x - 1]){
               cnt--;
               m[x]--;
               x++;
            }
         }
      }
      return cnt == 0;
   }
/**
print all the subsets whose sum equals to the given number

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

*/

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(arr.begin(), arr.end());

    combinationSum2Util(arr, 0, path, target, res);
    return res;
}

void combinationSum2Util(vector<int>& arr, int pos, vector<int> &path, int target, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(path);
        return;
    }

    if (pos == arr.size() || target - arr[pos] < 0) return;

    auto num = arr[pos++];

    path.push_back(num);
    combinationSum2Util(arr, pos, path, target - num, res);
    path.pop_back();
    
    // Skipping the duplicate numbers (sorted array)
    while (pos < arr.size() && arr[pos] == num) ++pos;  // This while loop can also be implemented in the above backtracking portion.

    combinationSum2Util(arr, pos, path, target, res);
}
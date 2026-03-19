class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp) {
        
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);

            // Stay at i (reuse allowed)
            backtrack(candidates, target - candidates[i], i, temp);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return result;
    }
};
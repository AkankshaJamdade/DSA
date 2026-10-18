class Solution {
public:
    
    int digitSum(int x) {
        int sum = 0;
        
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store {number, digit sum}
        vector<pair<int, int>> sorted;
        
        for (int x : nums) {
            sorted.push_back({x, digitSum(x)});
        }
        
        // Sort according to digit sum, then number
        sort(sorted.begin(), sorted.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second < b.second;
            
            return a.first < b.first;
        });
        
        // Map each number to its current position
        unordered_map<int, int> pos;
        
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        
        int swaps = 0;
        
        for (int i = 0; i < n; i++) {
            
            // Already contains the correct number
            if (nums[i] == sorted[i].first)
                continue;
            
            // Position of the number that should be here
            int j = pos[sorted[i].first];
            
            // Swap
            swap(nums[i], nums[j]);
            
            // Update positions
            pos[nums[j]] = j;
            pos[nums[i]] = i;
            
            swaps++;
        }
        
        return swaps;
    }
};
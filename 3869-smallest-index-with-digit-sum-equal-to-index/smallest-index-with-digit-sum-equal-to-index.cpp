class Solution {
public:
    int smallestIndex(vector<int>& nums) {
       
        for (int i = 0; i < nums.size(); i++) {
            int num=nums[i];
            int sum = 0;
            // one digit
            if (nums[i] < 10 && nums[i] == i) {
                return i;
            }
            // more than one digit
            if (num >= 10) {
                while (num != 0) {
                    int rem = num % 10;
                    sum += rem;
                    num = num / 10;
                }
                if (sum == i) {
                    return i;
                }
            }
        }
        return -1;
    }
};
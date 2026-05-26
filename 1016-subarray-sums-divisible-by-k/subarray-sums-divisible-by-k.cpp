class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;

        int prefixsum = 0, total = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixsum += nums[i];

            int rem = prefixsum % k;

            if(rem < 0){
                rem += k;
            }

            total += m[rem];   // directly add
            m[rem]++;          // update frequency
        }

        return total;
    }
};
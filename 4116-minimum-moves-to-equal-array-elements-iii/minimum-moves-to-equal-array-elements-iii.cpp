class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find max element first
        int maxNo=nums[0];
        for(int i=1; i<nums.size(); i++){
            maxNo=max(maxNo,nums[i]);
        }

        //moves 
        int moves=0;
        for(int i=0; i<nums.size(); i++){
            moves+=maxNo-nums[i];
        }

        return moves;
        
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int, vector<int>, greater<int>>p;
        //insert group of k element
        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }

        //traverse remainning
        for(int i=k; i<nums.size(); i++){
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);

            }
        }
        return p.top();

        
    }
};
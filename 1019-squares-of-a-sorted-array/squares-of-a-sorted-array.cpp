class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);

        int left=0, right=n-1;
        int pos=n-1;

        while(left<=right){
            int leftsq=nums[left]*nums[left];
            int rightsq=nums[right]*nums[right];

            if(leftsq > rightsq){
                result[pos]=leftsq;
                left++;
            }
            else{
                result[pos]=rightsq;
                right--;

            }

            
         pos--;
        }

        return result;
    }
};
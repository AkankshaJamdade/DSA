class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int square=1;
        int sum=0;
        int n=nums.size();

       

        for(int i=0; i<n; i++){
            if(n % (i+1) == 0){
                square= nums[i]*nums[i];
                sum += square;
            }
        }
        return sum;
        
    }
};
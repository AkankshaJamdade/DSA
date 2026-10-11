class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        

        for(int i=0; i<n; i++){
            int no=nums[i];
            int totalInt=0;
            while(no){
                no = no/10;
                totalInt++;
            }

            if(totalInt % 2 == 0){
                total++;
            }
        }
     return total;   
    }
};
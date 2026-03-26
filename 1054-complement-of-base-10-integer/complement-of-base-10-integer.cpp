class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
         return 1;

        int ans=0,mul=1,rem;
        while(n){
            rem=n%2;
            rem=1-rem;
            n=n/2;
            ans=ans+rem*mul;
            mul*=2;
        } 
        return ans;
        
    }
};
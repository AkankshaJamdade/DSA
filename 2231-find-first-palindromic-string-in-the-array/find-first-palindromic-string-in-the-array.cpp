class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string word : words){
            int left = 0;
            int right = word.length() - 1;
            bool isPal = true;

            while(left < right){
                if(word[left] != word[right]){
                    isPal = false;
                    break;
                }
                left++;
                right--;
            }

            if(isPal) return word;
        }

        return "";
    }
};
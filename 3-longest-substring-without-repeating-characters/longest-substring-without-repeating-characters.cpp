class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // store last index of each char

        int maxLen = 0;
        int start = 0; // left pointer of window

        for(int i = 0; i < s.size(); i++) {
            if(last[s[i]] >= start) {
                start = last[s[i]] + 1;
            }

            last[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
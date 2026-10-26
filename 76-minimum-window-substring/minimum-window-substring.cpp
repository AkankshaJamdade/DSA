class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;

        for(char ch : t)
            m[ch]++;

        int total = t.size();
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while(end < s.size()) {

            m[s[end]]--;

            if(m[s[end]] >= 0)
                total--;

            while(total == 0) {

                if(end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    startIndex = start;
                }

                m[s[start]]++;

                if(m[s[start]] > 0)
                    total++;

                start++;
            }

            end++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
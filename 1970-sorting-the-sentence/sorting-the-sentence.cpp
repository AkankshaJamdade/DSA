class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                int pos = temp.back() - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            }
            else{
                temp += s[i];
            }
        }

       
        int pos = temp.back() - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;

        string res;
        for(int i = 1; i <= count; i++){
            res += ans[i];
            res += ' ';
        }

        res.pop_back();
        return res;
    }
};
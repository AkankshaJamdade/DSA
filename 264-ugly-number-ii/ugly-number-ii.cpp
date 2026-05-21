class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);

        long long num = 1;

        for(int i = 1; i <= n; i++){
            num = *st.begin();   // smallest element
            st.erase(st.begin());

            st.insert(num * 2);
            st.insert(num * 3);
            st.insert(num * 5);
        }

        return num;
    }
};
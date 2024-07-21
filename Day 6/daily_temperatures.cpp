class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int> res(v.size(), 0);
        stack<pair<int, int>> st;
        st.push({v[v.size() - 1], v.size() - 1});
        int i;
        for (i = v.size() - 2; i >= 0; i--) {
            while (!st.empty() && st.top().first <= v[i]) {
                st.pop();
            }
            if (!st.empty()) {
                // res[i] already stores 0, just push v[i]
                res[i] = st.top().second - i;
            }
            st.push({v[i], i});
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> rt(t.size());
        for (int i = 0; i < t.size(); i++) {
            while (!st.empty() && t[st.top()] < t[i])
            {
                rt[st.top()] = i - st.top();   
                st.pop();
            }
            st.push(i);
        }
        return rt;
    }
};
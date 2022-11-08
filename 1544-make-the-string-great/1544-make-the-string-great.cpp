class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto c:s){
            if(st.empty() || abs(c-st.top()) != 32)st.push(c);
            else st.pop();
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(auto c:s){
            if(!ans.size() || abs(ans[ans.size()-1]-c) != 32)
                ans += c;
            else ans = ans.substr(0, ans.size()-1);
        }
        return ans;
    }
};
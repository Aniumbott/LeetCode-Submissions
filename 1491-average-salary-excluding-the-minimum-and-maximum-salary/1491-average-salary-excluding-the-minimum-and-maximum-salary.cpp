class Solution {
public:
    double average(vector<int>& salary) {
        double ans;
        int mn=INT_MAX, mx=INT_MIN;
        for(auto i:salary){
            ans += i;
            mx = max(mx, i);
            mn = min(mn, i);
        }
        ans -= (mn + mx);
        return ans/(salary.size()-2);
    }
};
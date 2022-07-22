class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MIN, m = INT_MAX, ans=0;
        for(int i=0; i<prices.size(); i++){
            l = max(l, prices[i] - m);
            m = min(prices[i], m);
            if(l > 0){ ans += l; l = INT_MIN; m = prices[i]; }
        }
        return ans;
    }
};
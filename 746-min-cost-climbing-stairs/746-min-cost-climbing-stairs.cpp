class Solution {
public:
    int helper(vector<int> cost, int in, vector<int> &mp){
        
        if(mp[in] != -1) return mp[in];
        
        if(in == cost.size()-1) return mp[in] = cost[in];
        
        if(in == cost.size()) return mp[in] == 0;
        
        // cout << in << endl;
        return mp[in] = cost[in] + min(helper(cost, in+1, mp), helper(cost, in+2, mp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mp(cost.size()+1, -1);
        return min(helper(cost, 0, mp), helper(cost, 1, mp));
    }
};
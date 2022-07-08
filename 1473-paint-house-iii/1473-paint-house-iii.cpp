class Solution {
private:
    vector<int> houses;
    vector<vector<int>> cost;
    int m, n;
    int target;
    long long dp[101][101][22];
public:
    long long helper(int in, int t, int p){
        if(t > target) return INT_MAX;
        if(in == m) return t == target?0:INT_MAX;
        if(dp[in][t][p] != -1) return dp[in][t][p];
        
        long long ans = INT_MAX;
        int nt = t;
        
        if(houses[in] != 0){
            nt = t;
            if(p != houses[in]) nt++;
            ans = min(ans, helper(in+1, nt, houses[in]));
        }
        else{
            for(int i=1; i<= n; i++){
                nt = t;
                if(p != i) nt++;
                ans = min(ans, helper(in+1, nt, i) + cost[in][i-1]);
            }
        }
        return dp[in][t][p] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->houses = houses;
        this->cost = cost;
        this->m = m;
        this->n = n;
        this->target = target;
        memset(dp, -1, sizeof(dp));
        long long ans = helper(0, 0, 21);
        return ans == INT_MAX?-1:ans;
    }
};
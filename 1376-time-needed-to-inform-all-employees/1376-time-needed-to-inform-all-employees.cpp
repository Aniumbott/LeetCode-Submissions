class Solution {
private:
    int helper(int ind, vector<int>& informTime){
        int ans = informTime[ind];
        
        if(mp[ind].size() == 0) return ans;
        int tp=0;
        for(int i=0; i<mp[ind].size(); i++){
            tp = max(tp, helper(mp[ind][i], informTime));
        }
        
        return ans + tp;
    }
    vector<int> mp[100001];
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0; i<n; i++){
            if(i == headID) continue;
            mp[manager[i]].push_back(i);
        }
        
        return helper(headID, informTime);
    }
};
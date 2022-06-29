class Solution {
public:
    int maxOperations(vector<int>& n, int k) {
        unordered_map<int,int> mp;
        int ct=0;
        for(auto i:n){
            mp[i]++;
        }
        for(int i=0; i<n.size(); i++){
            int j = k-n[i];
            if((n[i] != j) && (mp[n[i]] > 0 && mp[j] > 0)){
                ct+= min(mp[j], mp[n[i]]);
                mp[n[i]]-=ct;
                mp[j]-=ct;  
            }
            else if((n[i] == j) && mp[n[i]] > 1){
                ct += mp[n[i]]/2;
                mp[n[i]] -= ct*2;
            }
        }
        return ct;
    }
};
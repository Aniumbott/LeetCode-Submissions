class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> vp;
        
        vector<int> ans;
        
        for(auto &i:arr)
            vp.push_back({i, abs(i-x)});
        
        sort(vp.begin(), vp.end(), [](auto const &a, auto const &b){
            if(a.second == b.second)
                return a.first < b.first;
            else
                return a.second < b.second;
        });
        
        for(int i=0; i<k; i++)
            ans.push_back(vp[i].first);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
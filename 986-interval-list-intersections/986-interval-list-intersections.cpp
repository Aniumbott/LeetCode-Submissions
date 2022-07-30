class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i < f.size() && j < s.size()){
            int l = max(f[i][0], s[j][0]);
            int u = min(f[i][1], s[j][1]);
            if(l <= u) ans.push_back({ l, u });
            if(f[i][1] < s[j][1]) i++;
            else j++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> mp(points.size(), vector<int> (2,0)), ans;
        for(int i=0; i<points.size(); i++){
            mp[i][1] = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            mp[i][0] = i;
        }
        sort(mp.begin(), mp.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        for(int i=0; i<k; i++){
            ans.push_back(points[mp[i][0]]);
        }
        return ans;
    }
};
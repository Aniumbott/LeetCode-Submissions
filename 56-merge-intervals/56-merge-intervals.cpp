class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        vector<vector<int>> rt;
        
        if(v.size() == 0) {
            return rt;
        }
        
        sort(v.begin(), v.end());
        
        rt = {v[0]};
        
        int prt = 0;
        
        for(int i=1; i<v.size(); i++){
            if(v[i][0] <= rt[prt][1]){
                rt[prt][1] = max(rt[prt][1],v[i][1]);
            }
            else{
                rt.push_back({v[i][0], v[i][1]});
                prt++;
            }
        }
        return rt;
    }
};
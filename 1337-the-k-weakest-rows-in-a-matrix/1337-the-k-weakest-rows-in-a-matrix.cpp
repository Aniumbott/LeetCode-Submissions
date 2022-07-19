class Solution {
private:
    int getStrength(vector<int> & row) {
      auto first0 = lower_bound(row.begin(), row.end(), 0, greater<int>());
      return first0 - row.begin();  
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      set<pair<int, int>> st;
      for (int i = 0; i < mat.size(); ++i) { 
        st.emplace(getStrength(mat[i]), i); 
        if (st.size() > k) 
          st.erase(--st.end());  
      }    
      vector<int> res;
      for (auto& p : st)
        res.push_back(p.second);
      return res;
    }
};
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         vector<int> va, vb;
        int n = img1.size();
        unordered_map<int, int> ct;
        for (int i = 0; i < n * n; ++i)
            if (img1[i / n][i % n] == 1)
                va.push_back(i / n * 100 + i % n);
        for (int i = 0; i < n * n; ++i)
            if (img2[i / n][i % n] == 1)
                vb.push_back(i / n * 100 + i % n);
        for (int i : va) for (int j : vb) ct[i - j]++;
        int ans = 0;
        for (auto it : ct) ans = max(ans, it.second);
        return ans;   
    }
};
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int ans = 0;
        for (auto& s : arr) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a');
            int n = a.count();
            if (n < s.size()) continue;

            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset c = dp[i];
                if ((c & a).any()) continue;
                dp.push_back(c | a);
                ans = max(ans, (int)c.count() + n);
            }
        }
        return ans;
    }
};
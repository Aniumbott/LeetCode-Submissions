class Solution {
private:
    void dfs(int num, int n, int K, vector<int> &res) {
      if (n == 0) 
          res.push_back(num);
      else {
          int dig = num % 10;
          if (dig + K <= 9)
              dfs(num * 10 + dig + K, n - 1, K, res);
          if (K != 0 && dig >= K)
              dfs(num * 10 + dig - K, n - 1, K, res);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (auto num = 1; num <= 9; ++num) 
            dfs(num, n - 1, k, res);
        return res;
    }
};
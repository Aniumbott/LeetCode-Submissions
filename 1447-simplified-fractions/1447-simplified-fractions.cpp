class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        string c[n+1];
        
        for(int i=0; i<=n; i++) c[i] = to_string(i);
        
        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n; j++){
                if(__gcd(i,j) == 1)
                    ans.push_back(c[i]+'/'+c[j]);
            }
        }
        return ans;
    }
};
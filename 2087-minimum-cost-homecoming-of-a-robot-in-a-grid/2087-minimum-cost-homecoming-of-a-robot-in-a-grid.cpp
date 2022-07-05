class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& r, vector<int>& c) {
        int ans = 0;
        int a = h[0]>s[0]?1:-1;
        int b = h[1]>s[1]?1:-1;
        
        if(s[0] != h[0]){
            for(int i=s[0]+a; i != h[0]+a; i+=a)
            ans += r[i];    
        }
        
        if(s[1] != h[1]){
            for(int i=s[1]+b; i != h[1]+b; i+=b)
            ans += c[i];    
        }
        
        return ans;
    }
};
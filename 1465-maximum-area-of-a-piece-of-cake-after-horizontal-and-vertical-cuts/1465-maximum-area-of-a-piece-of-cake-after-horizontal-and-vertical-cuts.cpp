class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int hd= max(hc[0], h-hc[hc.size()-1]), vd = max(vc[0], w-vc[vc.size()-1]);
        
        long long mod = 1000000007;          
        if(hc.size() > 1){
            for(int i=1;i<hc.size(); i++)
                hd = max(hd, hc[i] - hc[i-1]);
        }
        
        if(vc.size() > 1){
            for(int i=1;i<vc.size(); i++)
                vd = max(vd, vc[i] - vc[i-1]);
        }
        
        long long ans = (long long)hd*vd;
        
        return ans%mod;
    }
};
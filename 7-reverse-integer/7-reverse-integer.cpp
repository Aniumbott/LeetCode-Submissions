class Solution {
public:
    int reverse(int x) {
        long long q = abs(x);
        long long int ans = 0;
        while(q>0){
            int t = q%10;
            ans = ans * 10 + t;
            q/=10;
        }
        
        if(x<0)
            ans = -ans;
        
        if(ans>=INT_MIN && ans<=INT_MAX)
            return ans;
        else
            return 0;
    }
};
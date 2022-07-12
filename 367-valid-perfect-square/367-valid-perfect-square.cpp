class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l=1, r=num/2;
        while(l <= r){
            int m = l+(r-l)/2;
            long long ml = (long long)m*m;
            if(ml == num) return true;
            else if(ml < num) l = m+1;
            else r = m-1;
        }
        return false;
    }
};
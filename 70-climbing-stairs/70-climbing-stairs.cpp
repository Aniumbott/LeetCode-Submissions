class Solution {
public:
    int climbStairs(int n) {
        if (n==1||n==2) return n;
        int p1 = 2, p2 = 1, i = 3;
        while(i <= n){
            int ans = p1 + p2;
            p2 = p1;
            p1 = ans;
            i++;
        }
        return p1;
    }
};
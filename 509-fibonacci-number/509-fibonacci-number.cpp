class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int p=1, q=0, i=2;
        while(i<=n){
            int ans = p+q;
            q = p;
            p = ans;
            i++;
        }
        return p;
    }
};
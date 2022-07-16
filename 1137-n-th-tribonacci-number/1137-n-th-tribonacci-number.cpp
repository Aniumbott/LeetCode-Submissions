class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        
        int p1=1, p2=0, p3=0, c=0;
        
        while(n-->1){
            c = p1+p2+p3;
            p3=p2;
            p2=p1;
            p1=c;
            // cout << c << " ";
        }
        return c;
    }
};
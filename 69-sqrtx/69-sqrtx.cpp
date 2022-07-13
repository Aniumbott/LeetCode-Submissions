class Solution {
public:
    int mySqrt(int x) {
        long long l=1;
        long long h=x;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid==x)return (int)mid;
            else if(mid*mid<x){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return (int)h;
    }
};
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left, right, mid;
        left = 1;
        right = n;
        int sol = 0;
        while (left<=right) {

            mid = left + (right-left)/2;  
            
            if(isBadVersion(mid)){
                sol = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
                               
        return sol;
    }
};
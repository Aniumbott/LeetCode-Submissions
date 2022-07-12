class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int l=1, r=a.size()-2;
        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m] > a[m-1] && a[m] > a[m+1]) return m;
            else if(a[m-1] > a[m]) r = m-1;
            else l = m+1;
        }
        return -1;
    }
};
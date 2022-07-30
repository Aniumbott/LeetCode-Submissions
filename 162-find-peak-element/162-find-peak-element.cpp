class Solution {
public:
    int findPeakElement(vector<int>& n) {
        if(n.size() == 1) return 0;
        if(n[0] > n[1]) return 0;
        if(n[n.size()-1] > n[n.size()-2]) return n.size()-1;
        int i=0, j=n.size();
        while(i <= j){
            int m = i + (j-i)/2;
            if(n[m] > n[m+1] && n[m] > n[m-1]) return m;
            else if(n[m] < n[m+1]) i = m+1;
            else j = m-1;
        }
        return -1;
    }
};
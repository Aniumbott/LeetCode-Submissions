class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int t) {
        int ans=0, i=0;
        sort(bt.begin(), bt.end(), [ ]( const vector<int>& lhs, const vector<int>& rhs ){
        return lhs[1] > rhs[1]; });
        while(i<bt.size()){
            if(t > bt[i][0]){
                ans += bt[i][0]*bt[i][1];
                t -= bt[i][0];
            }
            else{
                ans += t*bt[i][1];
                break;
            }
            i++;
        }
        return ans;
    }
};
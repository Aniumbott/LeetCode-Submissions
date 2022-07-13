class Solution {
private:
    int smallestDiff(int id, vector<int> arr2){
        int l=0, r=arr2.size()-1, ans=INT_MAX;
        while(l <= r){
            int m = l + (r-l)/2;
            if(arr2[m] == id) return 0;
            else if(arr2[m] > id) r = m-1;
            else l = m+1;
            ans = min(ans, abs(id - arr2[m]));
        }
        return ans;
    }
    
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0;
        sort(arr2.begin(), arr2.end());
        for(int i:arr1){
            int s = smallestDiff(i, arr2);
            if(s > d) ct++;
        }
        return ct;
    }
};
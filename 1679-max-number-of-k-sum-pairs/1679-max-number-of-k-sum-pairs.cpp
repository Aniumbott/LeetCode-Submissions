class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int cnt = 0;
        while(i<j)
        {
            if(arr[i]+arr[j]<k)
                i++;
            else if(arr[i]+arr[j]>k)
                j--;
            else {
                cnt++;
                i++,j--;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        vector<int>a(n+1); 
		
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            a[m[arr[i]]]++;  
            a[m[arr[i]]-1]--;
        }
     
        int sum =n/2;
        int ans=0;
        for(int i=n;i>0;i--){
            if(a[i]!=0){
            ans+=min(a[i],sum/i+(sum%i==0?0:1));  
                sum-=(a[i]*i);
            }

            if(sum<=0){
                   return ans;
               }
            
      }
      return ans;
    }
};
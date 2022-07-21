class Solution {
public:
    int jump(vector<int>& nums) {
        int n =  nums.size();
        
        if(n<2)return 0;
        
        int level=0,currentMax=0,i=0,nextMax=0;

         while(currentMax-i+1>0){		
             level++;
             for(;i<=currentMax;i++){	
                nextMax=max(nextMax,nums[i]+i);
                if(nextMax>=n-1)return level;  
             }
             currentMax=nextMax;
         }
        
	    return 0;
    }
};
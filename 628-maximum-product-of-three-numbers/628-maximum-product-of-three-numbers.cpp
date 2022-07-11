class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int max1, max2, max3;
        max1 = max2 = max3 = INT_MIN;
        int min1, min2, min3;
        min1 = min2 = min3 = INT_MAX;
        
        for(auto i: nums){
                if(i>max1){
                        max3 = max2;
                        max2 = max1;
                        max1 = i;
                }
                else if(i>max2){
                        max3 = max2;
                        max2 = i;
                }
                else if(i>max3){
                        max3 = i;
                }
                if(i<min1){
                        min2 = min1;
                        min1 = i;
                }else if(i<min2){
                        min2 = i;
                }
        }
        
        return max((max1*max2*max3),(min1*min2*max1));  
    }
};
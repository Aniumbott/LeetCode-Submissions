class Solution {
public:
    int nextgap(int gap){
            if(gap <= 1)
                return 0;
            return (gap/2) + (gap%2);
        }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int gap = m + n, i=0, j=0;
        for(gap = nextgap(gap); gap>0; gap=nextgap(gap)){
            
            for(i=0; i+gap < m; i++){
                if(nums1[i] > nums1[i+gap])
                    swap(nums1[i], nums1[i+gap]);
            }
            
            for(j = gap>m ? gap-m : 0; i<m && j<n; i++, j++){
                if(nums1[i] > nums2[j])
                    swap(nums1[i], nums2[j]);
            }
            
            for(i=0; i+gap < n; i++){
                if(nums2[i] > nums2[i+gap])
                    swap(nums2[i], nums2[i+gap]);
            }
        }
        
        for(i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
    }
};
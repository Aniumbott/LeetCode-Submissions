class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, k=0;
        while (j<nums2.size()){
            while (i<nums1.size() && nums1[i]>nums2[j]) i++;
            k = max(k,j-i);
            j++;
            if (i>=nums1.size()) break;
        }
        return k;
    }
};
class NumArray {
private:
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v.resize(nums.size());
        v[0] = nums[0];
        for(int i=1; i<nums.size(); i++){ v[i] = nums[i] + v[i-1]; }
    }
    
    int sumRange(int left, int right) {
        return (left == 0)?v[right]:v[right] - v[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
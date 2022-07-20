class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            long long pa = __builtin_popcount(a);
            long long pb = __builtin_popcount(b);
            return (pa == pb)?a<b:pa<pb;
        });
        return arr;
    }
};
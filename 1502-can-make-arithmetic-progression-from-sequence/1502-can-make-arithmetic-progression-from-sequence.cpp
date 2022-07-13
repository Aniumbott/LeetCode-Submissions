class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        
        if (arr.size() <= 2) return true;
        int mn = INT_MAX, mx = INT_MIN;
        for (int num : arr) { mn = min(mn, num); mx = max(mx, num); }
        if ((mx - mn) % (arr.size() - 1) != 0) return false;
        int d = (mx - mn) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == mn + i * d) i++;
            else if ((arr[i] - mn) % d != 0) return false;
            else {
                int pos = (arr[i] - mn) / d;
                if (arr[pos] == arr[i]) return false;
                swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};
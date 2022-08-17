class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size()-1;
        digits[l] += 1;
        while(l>0)
        {
            if(digits[l] > 9)
            {
                digits[l-1] += 1;
                digits[l] %= 10;
            }
            l--;
        }
        if (digits[0] > 9)
        {
            digits.insert(digits.begin(), 1);
            digits[1] %= 10;
        }
        return digits;
    }
};
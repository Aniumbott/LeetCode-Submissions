class Solution {
public:
    int dayOfYear(string date) {
        int months[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8));
                        
        int ans = months[m - 1] + d;
        
        if (m <= 2)
            return ans;
        
        if (y % 4 == 0 && y % 100 != 0)
            ans++;
        if(y % 400 == 0)
            ans++;
        
        return ans;
    }
};
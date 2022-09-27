class Solution {
public:
    string pushDominoes(string dominoes) {
        string d = 'L' + dominoes + 'R';
        string ans = "";
        for (int i = 0, j = 1; j < d.length(); ++j) {
            if (d[j] == '.') continue;
            int middle = j - i - 1;
            if (i > 0)
                ans += d[i];
            if (d[i] == d[j])
                ans += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                ans += string(middle, '.');
            else
                ans += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
            i = j;
        }
        return ans;
    }
};
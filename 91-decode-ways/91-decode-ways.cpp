class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), p = 0, p1 = 1, p2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0')
                p += p1;
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
            p += p2;
            p2 = p1;
            p1 = p;
            p = 0;
        }
        return p1;
    }
};
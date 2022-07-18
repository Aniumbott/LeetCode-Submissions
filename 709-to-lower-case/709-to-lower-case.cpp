class Solution {
public:
    string toLowerCase(string s) {
        int diff = 'a' - 'A';
        for(auto &c:s){ if(c <= 'Z' && c >= 'A') c += diff; }
        return s;
    }
};
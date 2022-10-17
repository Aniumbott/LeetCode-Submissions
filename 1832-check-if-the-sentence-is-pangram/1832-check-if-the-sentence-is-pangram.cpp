class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool mp[26] = {false};
        for(auto c:sentence){
            mp[c-'a'] = true;
        }
        int i = 0;
        while(i < 26){
            if(!mp[i]) return false;
            i++;
        }
        return true;
    }
};
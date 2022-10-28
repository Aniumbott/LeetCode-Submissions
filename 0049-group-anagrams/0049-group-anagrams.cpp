class Solution {
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) counter[c - 'a']++;
        string t;
        
        for (int c = 0; c < 26; c++) t += string(counter[c], c + 'a');
        
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto s:strs) mp[strSort(s)].push_back(s);

        vector<vector<string>> ans;
        
        for(auto i:mp) ans.push_back(i.second);
            
        return ans;
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mp[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> temp , ans ;
        for( int i = 0;  i < digits.size() ; i++ ){
            temp.push_back(mp[digits[i]-'0']);
        }
        
        get(0 , "" , temp , ans );
        return ans;
    }
    
    void get(int index , string s , vector<string> &temp , vector<string> &ans){
        if(index >= temp.size()){    
            string r = s;
            if(r != "")
                ans.push_back(r);
            return;
        }
        
        for(auto c : temp[index])
            get( index + 1 , s+c , temp , ans );
    }
};
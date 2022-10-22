class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128,0);
        for(auto c: t) mp[c]++;
        int ct=t.size(), begin=0, end=0, ans=INT_MAX, h=0;
        while(end<s.size()){
            if(mp[s[end++]]-->0) ct--;
            while(ct==0){
                if(end-begin<ans)  ans=end-(h=begin);
                if(mp[s[begin++]]++==0) ct++;
            }  
        }
        return ans==INT_MAX? "":s.substr(h, ans);
    }
};
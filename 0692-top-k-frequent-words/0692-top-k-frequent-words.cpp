class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>> mp;
        sort(words.begin(), words.end());
        
        for(int i=0; i<words.size(); i++){
            mp.push_back({words[i], 1});
            int ct=0;
            string tp = words[i];
            while(i < words.size() && tp == words[i]){ ct++; i++; }
            i--;
            mp[mp.size()-1].second = ct;

        }
        
        sort(mp.begin(), mp.end(), [](const auto &a, const auto &b){
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
        
        vector<string> ans;
        for(int i=0; i<k; i++) ans.push_back(mp[i].first);
        
        return ans;
    }
};
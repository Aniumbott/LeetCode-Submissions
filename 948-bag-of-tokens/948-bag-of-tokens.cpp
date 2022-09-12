class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l=0, r=tokens.size()-1, s=0, ans = 0;
        while(l <= r){
            if(power >= tokens[l]){
                power -= tokens[l++];
                ans = max(ans,++s);
            }
            else if(s > 0){
                power += tokens[r--];
                s--;
            }
            else break;
        }
        return ans;
    }
};
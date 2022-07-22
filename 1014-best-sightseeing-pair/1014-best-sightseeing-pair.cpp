class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        
        int n = values.size(), maxScore = 0;
        int maxLeft = values[0] + 0;
        for(int j = 1; j < n; j++) {
            maxScore = max(maxScore, maxLeft + values[j] - j);
            maxLeft = max(maxLeft, values[j] + j);
        }
        return maxScore;
    }
};
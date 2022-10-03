class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size(), tans = neededTime[0], mx = neededTime[0];
        for(int i=1; i<n; i++){
            if(colors[i] == colors[i-1]){
                while(i < n && colors[i] == colors[i-1]){
                    tans +=neededTime[i];
                    mx = max(mx, neededTime[i]);
                    i++;
                }
                tans -= mx;
                ans += tans;
                i--;
            }
            else{
                tans = neededTime[i];
                mx = neededTime[i];
            }
        }
        return ans;
    }
};
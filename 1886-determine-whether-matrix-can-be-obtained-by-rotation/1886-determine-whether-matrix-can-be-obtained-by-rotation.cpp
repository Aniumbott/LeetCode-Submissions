class Solution {
public:
    bool findRotation(vector<vector<int>>& a, vector<vector<int>>& b) {
        bool c[] = {true, true, true, true};
        int n=a.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=b[i][j]) c[0]=false;
                if(a[i][j]!=b[n-j-1][i]) c[1]=false;
                if(a[i][j]!=b[n-i-1][n-j-1]) c[2]=false;
                if(a[i][j]!=b[j][n-i-1]) c[3]=false;
            }
        }
            
        return c[0]||c[1]||c[2]||c[3];
    }
};
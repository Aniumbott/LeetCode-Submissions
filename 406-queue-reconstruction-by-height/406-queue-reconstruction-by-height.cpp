class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        for(int i=p.size()-2; i>=0; i--){
            if(p[i][1] > 0){
                int j=i-1;
                while(j >= 0 && p[i][0] == p[j][0]) j--;
                j = p[i][1] - (i-j-1);
                if(j != 0){
                    vector<int> c = {p[i][0],p[i][1]};
                    int k;
                    for(k=i; k<(i+j); k++){
                        p[k][0] = p[k+1][0];
                        p[k][1] = p[k+1][1];
                    }
                    p[k][0] = c[0];
                    p[k][1] = c[1];
                }
            }    
        }
        return p;
    }
};
class Solution {
private:
    int c, v;
    void helper(vector<vector<int>>& a, int x, int y){
        if(x == a.size() || y == a[0].size() || x<0 || y<0) return;
        if(a[x][y] != v) return;
        a[x][y] = c;
        helper(a, x+1, y);
        helper(a, x-1, y);
        helper(a, x, y+1);
        helper(a, x, y-1);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->c = color;
        this->v = image[sr][sc];
        if(v != c) helper(image, sr, sc);
        return image;
    }
};
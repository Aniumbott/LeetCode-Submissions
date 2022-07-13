class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<int> a(2,0);
        int i=0, j=0;
        while(i < s1.size()){
            if(s1[i] != s2[i]){
                if(j == 2) return false;
                a[j] = i;
                j++;
            }
            i++;
        }
        swap(s1[a[0]], s1[a[1]]);
        return (s1[a[0]] == s2[a[0]])&&(s1[a[1]] == s2[a[1]]);
    }
};
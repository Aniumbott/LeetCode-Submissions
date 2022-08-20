class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = -1, l=0;
        for(int i = s.size()-1; i >=0 && c; i--)
        {
            if(s[i] != ' ')
            {
                l++;
                c=1;
            }
            else
                if (c==1)
                    c=0;
        }
        return l;
    }
};
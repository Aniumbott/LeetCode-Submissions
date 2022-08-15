class Solution {
public:
    int romanToInt(string s) {
        int n=0, i=0;
        while(s[i] != '\0')
        {
            if (s[i] == 'I')
                n = n + 1;
            else if (s[i] == 'V')
                n = n + 5;
            else if (s[i] == 'X')
                n = n + 10;
            else if (s[i] == 'L')
                n = n + 50;
            else if (s[i] == 'C')
                n = n + 100;
            else if (s[i] == 'D')
                n = n + 500;
            else if (s[i] == 'M')
                n = n + 1000;
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                n = n - 2;
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
                n = n - 20;
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                n = n - 200;
            i++;
        }
        return n;
    }
};
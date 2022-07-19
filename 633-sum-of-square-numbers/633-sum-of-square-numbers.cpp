class Solution {
public:
    bool judgeSquareSum(int c) {
      long int h = sqrt(c), l=0;
        while(h>=l){
            long int k=h*h+0L+l*l;
            if(k==c)
                return 1;
            else if(k>c)
                h--;
            else
                l++;
        }
        return 0;
    }
};
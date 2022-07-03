class Solution {
public:
    int helper(int num, int i, int k){
        if((i*k)%10 == k) return -1;
        if((i*k)%10 == num%10)
        {
            cout << i << " ";
            if(num >= i*k) return i;
            else return -1;
        } 
        return helper(num, i+1, k);
    }
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        if(k == num%10) return 1;
        if(k > num) return -1;
        return helper(num, 2, k);
    }
};
class Solution {
private:
    int squareDigits(int n){
        cnt++;
        int sum = 0;
        while (n) sum += pow((n % 10), 2) , n /= 10;
        return sum;
    }
    
public:
    int cnt;
    bool isHappy(int n) {
        if (cnt > n) return false;
        if (squareDigits(n) == 1) return true;
        return isHappy(squareDigits(n));
    }
};
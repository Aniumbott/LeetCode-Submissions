class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long c = counter(n);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }

    long counter(int a) {
        long res = 0;
        for (; a; a /= 10) res += pow(10, a % 10);
        return res;
    }
};
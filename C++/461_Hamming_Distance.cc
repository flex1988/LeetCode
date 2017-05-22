class Solution {
   public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int r = 0;

        while (n) {
            if (n & 1)
                r++;
            n /= 2;
        }

        return r;
    }
};

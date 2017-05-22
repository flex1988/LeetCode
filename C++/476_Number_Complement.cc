class Solution {
   public:
    int findComplement(int num) {
        int mask = 1;
        int i;

        for (i = 1; i < 32; i++) {
            mask *= 2;
            if (mask > num)
                break;
        }

        mask -= 1;
        return mask ^ num;
    }
};

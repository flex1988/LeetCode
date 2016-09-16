// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 0;
        int high = n;

        while (low <= high) {
            if (low == high) return low;
            int guessNum = low / 2 + high / 2;
            int ret = guess(guessNum);
            if (ret == 0)
                return guessNum;
            else if (ret == -1)
                high = guessNum - 1;
            else
                low = guessNum + 1;
        }
        return 0;
    }
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if (digits[digitsSize - 1] < 9) {
        digits[digitsSize - 1]++;
        *returnSize = digitsSize;
        return digits;
    }
    else {
        int carry = 1;
        int* ret = malloc(sizeof(int) * digitsSize + 1);
        int index = digitsSize - 1;
        while (carry && index > 0) {
            int curr = digits[index] + 1;
            if (curr > 9) {
                carry = 1;
                ret[index + 1] = 0;
                index--;
            }
            else {
                carry = 0;
                ret[index + 1] = curr;
                index--;
            }
        }
        if (carry == 0) {
            *returnSize = digitsSize;
            memcpy(ret + 1, digits, sizeof(int) * index + 1);
            return ret + 1;
        }
        else if (index == 0) {
            memcpy(ret + 1, digits, sizeof(int) * index + 1);
            int next = ret[1] + 1;
            if (next > 9) {
                ret[1] = 0;
                ret[0] = 1;
                *returnSize = digitsSize + 1;
                return ret;
            }
            else {
                ret[1] = next;
                *returnSize = digitsSize;
                return ret + 1;
            }
        }
        else {
            *returnSize = digitsSize + 1;
            ret[0] = 1;
            return ret;
        }
    }
}

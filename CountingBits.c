/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    int* ret = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    int index = 0;
    for (int i = 0; i <= num; i++) {
        int count = 0;
        if (i == 0)
            ret[i] = 0;
        else if (i % 2 == 1)
            ret[i] = ret[i - 1] + 1;
        else {
            int n = i;
            while (n) {
                if (n % 2 == 1)
                    count++;
                n = n >> 1;
            }
            ret[i] = count;
        }
    }
    return ret;
}

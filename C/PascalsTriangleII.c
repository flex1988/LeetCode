/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    int* tmp = calloc(rowIndex + 1, sizeof(int));
    int* ret = calloc(rowIndex + 1, sizeof(int));
    for (int i = 0; i <= rowIndex; i++) {
        if (i == 0)
            ret[0] = 1;
        else {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    ret[j] = 1;
                }
                else {
                    ret[j] = tmp[j - 1] + tmp[j];
                }
            }
        }

        for (int n = 0; n <= i; n++)
            tmp[n] = ret[n];
    }
    *returnSize = rowIndex + 1;

    return ret;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int));
    int len = pow(2, n);
    int index = 0;
    for (int i = 0; i < len; i++) {
        ret = (int*)realloc(ret, (index + 1) * sizeof(int));
        ret[index++] = i ^ (i >> 1);
    }
    *returnSize = index;
    return ret;
}

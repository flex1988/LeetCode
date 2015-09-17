/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int idx1 = 0;
    int idx2 = 1;
    int* ret = malloc(2 * sizeof(int));
    for (; idx2 < numsSize; idx2++) {
        idx1 = 0;
        for (; idx1 < idx2; idx1++) {
            if (nums[idx1] + nums[idx2] == target) {
                ret[0] = idx1 + 1;
                ret[1] = idx2 + 1;
                return ret;
            }
        }
    }
}

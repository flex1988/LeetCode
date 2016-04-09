/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b);
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ret = NULL;
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int target = -nums[i];
        int l = i + 1;
        int h = numsSize - 1;
        while (l < h) {
            int sum = nums[l] + nums[h];
            if (sum > target) {
                h--;
            }
            else if (sum < target) {
                l++;
            }
            else {
                int* t = (int*)malloc(sizeof(int) * 3);
                t[0] = nums[i];
                t[1] = nums[l++];
                t[2] = nums[h--];
                (*returnSize)++;
                ret = (int**)realloc(ret, sizeof(int*) * (*returnSize));
                ret[*returnSize - 1] = t;
                while (t[1] == nums[l])
                    l++;
                while (nums[h] == t[2])
                    h--;
            }
        }
        while (nums[i] == nums[i + 1])
            i++;
    }

    return ret;
}

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

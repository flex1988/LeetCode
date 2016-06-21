/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int pivot = numsSize / 2;
    int size = numsSize % 2 == 0 ? pivot : pivot + 1;
    *returnSize = 2;

    if (numsSize == 1) {
        int* ret = malloc(sizeof(int) * 2);
        if (nums[0] != target) {
            ret[0] = -1;
            ret[1] = -1;
        }
        else {
            ret[0] = 0;
            ret[1] = 0;
        }
        return ret;
    }
    else if (nums[numsSize - 1] < target || nums[0] > target) {
        int* ret = malloc(sizeof(int) * 2);
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    else if (nums[pivot] < target) {
        printf("%d %d", pivot);
        int* ret = searchRange(nums + pivot, size, target, returnSize);
        if (*ret != -1) {
            *ret += pivot;
            *(ret + 1) += pivot;
        }
        return ret;
    }
    else if (nums[pivot] > target)
        return searchRange(nums, pivot, target, returnSize);
    else if (nums[pivot] == target) {
        int* left = searchRange(nums, pivot, target, returnSize);
        int* right = searchRange(nums + pivot, size, target, returnSize);
        if (*right != -1) {
            *right += pivot;
            *(right + 1) += pivot;
        }

        int* ret = malloc(sizeof(int) * 2);
        ret[0] = left[0] == -1 ? right[0] : left[0];
        ret[1] = right[1];
        return ret;
    }
}

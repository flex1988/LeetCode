int searchInsert(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int pivot = 0;

    while (l <= r) {
        pivot = (r + l) / 2;

        if (nums[pivot] == target) {
            return pivot;
        }

        if (nums[pivot] < target) {
            l = pivot + 1;
        }
        else {
            r = pivot - 1;
        }
    }
    return l;
}

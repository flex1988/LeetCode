void sortColors(int* nums, int numsSize)
{
    if (numsSize < 2)
        return;
    int pivot = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < nums[numsSize - 1]) {
            int t = nums[pivot];
            nums[pivot] = nums[i];
            nums[i] = t;
            pivot++;
        }
    }
    int t = nums[pivot];
    nums[pivot] = nums[numsSize - 1];
    nums[numsSize - 1] = t;
    sortColors(nums, pivot);
    sortColors(nums + pivot + 1, numsSize - pivot - 1);
}

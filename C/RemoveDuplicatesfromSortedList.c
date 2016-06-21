int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
        return 1;
    int index = 0;
    int i = 0, j = 1;
    for (; i < numsSize && j < numsSize;) {
        if (nums[j] > nums[i]) {
            nums[i + 1] = nums[j];
            i++;
            j++;
        }
        else if (nums[j] == nums[i]) {
            j++;
        }
    }
    return i + 1;
}

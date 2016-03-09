int removeDuplicates(int* nums, int numsSize)
{
    int index = 0;
    bool isDup = false;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            nums[index++] = nums[i];
        }
        else if (nums[i - 1] == nums[i]) {
            if (!isDup) {
                nums[index++] = nums[i];
                isDup = true;
            }
        }
        else {
            nums[index++] = nums[i];
            isDup = false;
        }
    }
    return index;
}

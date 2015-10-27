int majorityElement(int* nums, int numsSize)
{
    int i = 0, count = 0;
    int idx = nums[0];
    for (; i < numsSize; i++) {
        if (idx == nums[i])
            count++;
        else
            count--;
        if (count < 0) {
            idx = nums[i];
            count = 1;
        }
    }
    return idx;
}

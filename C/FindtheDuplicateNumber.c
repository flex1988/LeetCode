int findDuplicate(int* nums, int numsSize)
{
    if (numsSize == 1)
        return -1;
    int slow = nums[0];
    int fast = nums[slow];
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

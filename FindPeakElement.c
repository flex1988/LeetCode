int findPeakElement(int* nums, int numsSize)
{
    int slow = -1;
    int fast = 0;
    int order = 0;
    while (slow < numsSize) {
        if (nums[slow] < nums[fast] && fast < numsSize) {
            slow++;
            fast++;
            order = 1;
        }
        else if (slow == (numsSize - 1) || nums[slow] > nums[fast]) {
            if (order == 1)
                return slow;
            order = 2;
            slow++;
            fast++;
        }
    }
    return 0;
}

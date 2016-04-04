bool recursive(int* nums, int low, int high);
void nextPermutation(int* nums, int numsSize)
{
    if (!recursive(nums, 0, numsSize - 1)) {
        reverse(nums, numsSize);
    }
}

bool recursive(int* nums, int low, int high)
{
    if (low >= high)
        return false;
    if (!recursive(nums, low + 1, high)) {
        for (int i = high; i > low; i--) {
            if (nums[i] > nums[low]) {
                int t = nums[i];
                nums[i] = nums[low];
                nums[low] = t;
                reverse(nums + low + 1, high - low);
                return true;
            }
        }
        return false;
    }
    return true;
}

void reverse(int* nums, int numsSize)
{
    int mid = numsSize / 2;
    for (int i = 0; i < mid; i++) {
        int t = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = t;
    }
}

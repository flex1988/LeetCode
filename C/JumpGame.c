#define MAX(a, b) (((a) > (b)) ? (a) : (b))
bool canJump(int* nums, int numsSize)
{
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (max < i)
            return false;
        max = MAX(max, nums[i] + i);
        if (max >= numsSize - 1)
            return true;
    }
}

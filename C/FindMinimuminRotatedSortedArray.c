#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int findMin(int* nums, int numsSize)
{
    int l = nums[0];
    if (numsSize == 1)
        return l;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1])
            return MIN(l, nums[i + 1]);
    }
    return l;
}

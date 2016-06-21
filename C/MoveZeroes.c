void moveZeroes(int* nums, int numsSize)
{
    int range = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            range++;
        else if (nums[i] != 0 && range > 0) {
            nums[i - range] = nums[i];
            nums[i] = 0;
        }
    }
}

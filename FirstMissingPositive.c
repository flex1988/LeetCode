int firstMissingPositive(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 1;

    int* arr = malloc(sizeof(int) * numsSize);
    memset(arr, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0 && nums[i] <= numsSize)
            arr[nums[i] - 1] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (arr[i] <= 0)
            return i + 1;
    }
    return numsSize + 1;
}

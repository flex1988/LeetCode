int cmp(const void* a, const void* b);
int
threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    if (numsSize <= 3) return nums[0] + nums[1] + nums[2];
    int ret = nums[0] + nums[1] + nums[numsSize - 1];
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(target - sum) < abs(target - ret)) {
                ret = sum;
            }
            if (ret == target) return target;
            sum > target ? k-- : j++;
        }
    }
    return ret;
}

int
cmp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

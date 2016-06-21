bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    if (k == 0)
        return false;
    if (numsSize == 1)
        return false;
    if (k >= numsSize) {
        for (int i = 0; i < numsSize; i++) {
            for (int j = i; j < numsSize; j++) {
                if (nums[i] == nums[j] && i != j)
                    return true;
            }
        }
    }
    else {
        for (int i = 0; i <= k; i++) {
            for (int j = i + 1; j <= k; j++) {
                if (nums[i] == nums[j] && i != j)
                    return true;
            }
        }
        for (int n = k + 1; n < numsSize; n++) {
            for (int m = n - k; m < n; m++) {
                if (nums[m] == nums[n] && m != n)
                    return true;
            }
        }
    }
    return false;
}

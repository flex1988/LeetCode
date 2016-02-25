void rotate(int nums[], int n, int k)
{
    if (k == 0)
        return;
    if (k >= n)
        k %= n;
    for (int i = 0; i < k; i++) {
        int tmp = nums[n - k + i];
        for (int j = 0; j < n - k; j++) {
            nums[n - k - j + i] = nums[n - k - j - 1 + i];
        }
        nums[i] = tmp;
    }
}

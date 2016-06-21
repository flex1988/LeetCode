void merge(int* nums1, int m, int* nums2, int n)
{
    if (n == 0)
        return;
    int i = m + n - 1, j = 0;
    for (; i >= 0; i--) {
        nums1[i] = nums1[i - n];
    }
    i = n;
    for (int k = 0; k < m + n; k++) {
        if (i == m + n && j < n) {
            nums1[k] = nums2[j];
            j++;
        }
        else if (j == n && i < m + n) {
            nums1[k] = nums1[i++];
        }
        else if (nums1[i] > nums2[j]) {
            nums1[k] = nums2[j];
            j++;
        }
        else if (nums1[i] <= nums2[j]) {
            nums1[k] = nums1[i];
            i++;
        }
    }
}

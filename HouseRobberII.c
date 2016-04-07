int rob(int* nums, int numsSize)
{
    if (numsSize <= 0)
        return 0;
    int result1[numsSize];
    int path1[numsSize];
    int result2[numsSize];
    int path2[numsSize];

    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            result1[0] = nums[0];
            path1[0] = 1;
            result2[0] = 0;
            path2[0] = 0;
        }
        else if (i == 1) {
            result1[1] = result1[0];
            path1[1] = 0;
            result2[1] = nums[1];
            path2[1] = 1;
        }
        else if (i == numsSize - 1) {
            result1[i] = result1[i - 1];
            path1[i] = 0;
            if (path2[i - 1]) {
                if (result2[i - 1] > (result2[i - 2] + nums[i])) {
                    path2[i] = 0;
                    result2[i] = result2[i - 1];
                }
                else {
                    path2[i] = 1;
                    result2[i] = result2[i - 2] + nums[i];
                }
            }
            else {
                result2[i] = result2[i - 1] + nums[i];
                path2[i] = 1;
            }
        }
        else {
            if (path1[i - 1]) {
                if (result1[i - 1] > (result1[i - 2] + nums[i])) {
                    path1[i] = 0;
                    result1[i] = result1[i - 1];
                }
                else {
                    path1[i] = 1;
                    result1[i] = result1[i - 2] + nums[i];
                }
            }
            else {
                path1[i] = 1;
                result1[i] = result1[i - 1] + nums[i];
            }
            if (path2[i - 1]) {
                if (result2[i - 1] > (result2[i - 2] + nums[i])) {
                    path2[i] = 0;
                    result2[i] = result2[i - 1];
                }
                else {
                    path2[i] = 1;
                    result2[i] = result2[i - 2] + nums[i];
                }
            }
            else {
                path2[i] = 1;
                result2[i] = result2[i - 1] + nums[i];
            }
        }
    }

    return result1[numsSize - 1] > result2[numsSize - 1] ? result1[numsSize - 1] : result2[numsSize - 1];
}

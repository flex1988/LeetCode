int search(int* nums, int numsSize, int target)
{
    if (numsSize == 1)
        return nums[0] == target ? 0 : -1;
    int index = 0;
    if (nums[0] < nums[numsSize - 1]) {
        if (target < nums[0] || target > nums[numsSize - 1])
            return -1;
        while (index < numsSize) {
            if (nums[index] == target)
                return index;
            else if (nums[index] > target)
                return -1;
            index++;
        }
    }
    else {
        if (target < nums[0]) {
            index = numsSize - 1;
            while (nums[index] > nums[index - 1]) {
                if (target == nums[index])
                    return index;
                else if (target > nums[index])
                    return -1;
                index--;
            }

            return nums[index] == target ? index : -1;
        }
        else {
            while (nums[index] < nums[index + 1]) {
                if (target == nums[index])
                    return index;
                else if (target < nums[index])
                    return -1;
                index++;
            }
            return nums[index] == target ? index : -1;
        }
    }
}

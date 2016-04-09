struct NumArray {
    int* nums;
    int numsSize;
    int* tables;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize)
{
    struct NumArray* arr = malloc(sizeof(struct NumArray));
    arr->tables = (int*)malloc(sizeof(int) * numsSize);
    arr->nums = nums;
    arr->numsSize = numsSize;
    for (int i = 0; i < numsSize; i++)
        arr->tables[i] = i == 0 ? nums[0] : arr->tables[i - 1] + nums[i];

    return arr;
}

int sumRange(struct NumArray* numArray, int i, int j) { return numArray->tables[j] - (i == 0 ? 0 : numArray->tables[i - 1]); }

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray)
{
    free(numArray->tables);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

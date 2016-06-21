/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;
    struct TreeNode* t = malloc(sizeof(struct TreeNode*));
    int len = numsSize / 2;
    t->val = nums[len];
    t->left = sortedArrayToBST(nums, len);
    t->right = sortedArrayToBST(nums + len + 1, numsSize - 1 - len);
    return t;
}

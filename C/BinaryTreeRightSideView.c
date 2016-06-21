/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int* ret, struct TreeNode* root, int* size, int depth)
{
    if (ret[depth] == 0)
        (*size)++;
    ret[depth] = root->val;

    if (root->left)
        dfs(ret, root->left, size, depth + 1);
    if (root->right)
        dfs(ret, root->right, size, depth + 1);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    if (!root)
        return NULL;
    int* ret = calloc(100, sizeof(int));
    *returnSize = 0;
    dfs(ret, root, returnSize, 0);
    return ret;
}

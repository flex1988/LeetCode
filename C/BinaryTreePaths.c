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
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int left = 0;
    char** leftret;
    int right = 0;
    char** rightret;
    if (root->left) {
        leftret = binaryTreePaths(root->left, &left);

        *returnSize += left;
    }
    if (root->right) {
        rightret = binaryTreePaths(root->right, &right);
        *returnSize += right;
    }

    char** ret = malloc(sizeof(char*) * (*returnSize + 1));
    char* val = malloc(sizeof(char) * 10);
    sprintf(val, "%d", root->val);
    int offset = strlen(val);
    if (!root->left && !root->right) {
        char* t = malloc(sizeof(char) * 10);
        sprintf(t, "%d", root->val);
        ret[0] = t;
        *returnSize = 1;
        return ret;
    }

    for (int i = 0; i < *returnSize; i++) {

        if (i < left) {
            int len = strlen(leftret[i]);
            char* t = malloc(sizeof(char) * (len + 10));
            memcpy(t, val, offset * sizeof(char));
            t[offset] = '-';
            t[offset + 1] = '>';
            memcpy(t + offset + 2, leftret[i], len * sizeof(char));
            t[offset + 2 + len] = '\0';
            ret[i] = t;
        }
        else {

            int len = strlen(rightret[i - left]);
            char* t = malloc(sizeof(char) * (len + 10));
            memcpy(t, val, offset * sizeof(char));
            t[offset] = '-';
            t[offset + 1] = '>';
            memcpy(t + offset + 2, rightret[i - left], len * sizeof(char));
            t[offset + 2 + len] = '\0';
            ret[i] = t;
        }
    }
    return ret;
}

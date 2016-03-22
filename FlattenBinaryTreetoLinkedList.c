/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int* recursion(struct TreeNode* root, int* retSize);

void flatten(struct TreeNode* root)
{
    int size = 0;
    int* ret = recursion(root, &size);
    printf("%d\n", size);
    struct TreeNode* q = root;
    for (int i = 0; i < size; i++) {
        q->val = ret[i];
        q->left = NULL;
        if (i != size - 1) {
            q->right = malloc(sizeof(struct TreeNode*));
            q = q->right;
        }
    }
}

int* recursion(struct TreeNode* root, int* retSize)
{

    if (!root)
        return NULL;
    *retSize = 1;
    int leftSize = 0;
    int* left;
    if (root->left)
        left = recursion(root->left, &leftSize);
    if (leftSize != 0)
        *retSize += leftSize;
    int rightSize = 0;
    int* right;
    if (root->right)
        right = recursion(root->right, &rightSize);
    if (rightSize != 0)
        *retSize += rightSize;

    int* ret = malloc(sizeof(int*) * (*retSize));
    ret[0] = root->val;
    memcpy(ret + 1, left, sizeof(int) * leftSize);
    memcpy(ret + 1 + leftSize, right, sizeof(int) * rightSize);
    return ret;
}

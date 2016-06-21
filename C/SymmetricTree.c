/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool compare(struct TreeNode* p, struct TreeNode* q);

bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;
    return compare(root->left, root->right);
}

bool compare(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false;
    else if (p->val != q->val)
        return false;
    else
        return compare(p->left, q->right) && compare(p->right, q->left);
}

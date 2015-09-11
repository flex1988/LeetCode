/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isAncestor(struct TreeNode* node, struct TreeNode* t);

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (isAncestor(root->left, p) && isAncestor(root->left, q))
        return lowestCommonAncestor(root->left, p, q);
    else if (isAncestor(root->right, p) && isAncestor(root->right, q))
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

bool isAncestor(struct TreeNode* node, struct TreeNode* t)
{
    if (!node)
        return false;
    else if (node->val == t->val)
        return true;
    else if ((node->left && node->left->val == t->val) || (node->right && node->right->val == t->val))
        return true;
    else
        return isAncestor(node->left, t) || isAncestor(node->right, t);
}

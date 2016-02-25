/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* bstify(struct ListNode* head, int length)
{
    if (head == NULL || length == 0)
        return NULL;
    if (length == 1) {
        struct TreeNode* t = malloc(sizeof(struct TreeNode));
        t->val = head->val;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    else {

        int tmp = length / 2;
        struct ListNode* tmp_node = head;
        while (tmp--) {
            tmp_node = tmp_node->next;
        }
        struct TreeNode* t = malloc(sizeof(struct TreeNode));
        t->val = tmp_node->val;
        t->left = bstify(head, length / 2);
        t->right = bstify(tmp_node->next, length - length / 2 - 1);
        return t;
    }
}
struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int length = 0;
    struct ListNode* p = head;
    while (p) {
        length++;
        p = p->next;
    }

    return bstify(head, length);
}

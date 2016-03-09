/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head)
        return NULL;
    struct ListNode** stack = malloc(sizeof(struct ListNode*) * 100);
    struct ListNode* p = head;
    int index = 0;
    stack[index++] = p;
    p = p->next;
    bool isPop = false;
    while (p) {
        if (stack[index - 1]->val == p->val) {
            isPop = true;
        }
        else {
            if (isPop)
                index--;
            stack[index++] = p;
            isPop = false;
        }
        p = p->next;
    }
    if (isPop) {
        index--;
        if (index == 0)
            return NULL;
    }
    struct ListNode* ret = stack[0];
    p = ret;
    for (int i = 1; i < index; i++) {
        p->next = stack[i];
        p = p->next;
    }
    p->next = NULL;
    return ret;
}

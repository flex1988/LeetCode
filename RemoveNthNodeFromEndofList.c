/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeFunc(struct ListNode* pre, struct ListNode* cur, int n);

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int length = 0;
    struct ListNode* p = head;
    while (p) {
        length++;
        p = p->next;
    }
    if (length == 1)
        return NULL;
    int span = length - n;
    if (span == 0)
        return head->next;
    removeFunc(head, head->next, span);
    return head;
}

struct ListNode* removeFunc(struct ListNode* pre, struct ListNode* cur, int n)
{
    if (n == 1)
        pre->next = cur->next ? cur->next : NULL;
    else
        removeFunc(cur, cur->next, --n);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    struct ListNode* p = head->next;
    struct ListNode* q = swapPairs(p->next);
    p->next = head;
    head->next = q;
    return p;
}

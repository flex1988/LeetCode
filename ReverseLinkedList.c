/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return head;
    struct ListNode* q = head;
    struct ListNode* p = q->next;
    struct ListNode* r;
    q->next = NULL;
    while (p->next != NULL) {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    p->next = q;
    return p;
}

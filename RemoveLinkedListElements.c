/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* p = head;
    struct ListNode* q = p;
    if (q == NULL || (q->val == val && q->next == NULL))
        return NULL;
    while (q != NULL) {
        if (q->val != val) {
            head = q;
            p = q;
            break;
        }
        q = q->next;
    }
    if (q == NULL)
        return NULL;
    while (p != NULL) {
        p = p->next;
        if (p == NULL) {
            q->next = NULL;
            return head;
        }
        else if (p->val != val) {
            q->next = p;
            q = q->next;
        }
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (k == 0 || !head || !head->next)
        return head;
    struct ListNode* p = head;
    struct ListNode* q;
    struct ListNode* r;
    struct ListNode* t;
    int nums = 0;
    while (p) {
        nums++;
        r = p;
        p = p->next;
    }
    if (nums == k)
        return head;
    p = head;
    k %= nums;
    if (k == 0)
        return head;
    while (p) {
        if (nums-- == k + 1) {
            q = p;
            t = p->next;
        }
        p = p->next;
    }
    r->next = head;
    q->next = NULL;
    return t;
}

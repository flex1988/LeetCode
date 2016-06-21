/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseLinkedList(struct ListNode* head, struct ListNode** tail, int n);

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (m == n)
        return head;
    struct ListNode* tail = NULL;
    struct ListNode* p = head;
    struct ListNode* first = NULL;
    struct ListNode* q = NULL;
    struct ListNode* r = NULL;

    int t = m;
    while (t > 1) {
        first = p;
        r = first->next;
        p = p->next;
        t--;
    }
    q = reverseLinkedList(p, &tail, n - m + 1);
    if (first) {
        first->next = q;
        r->next = tail;
        return head;
    }
    else {
        head->next = tail;
        return q;
    }
}

struct ListNode* reverseLinkedList(struct ListNode* head, struct ListNode** tail, int n)
{
    if (n > 1) {
        struct ListNode* h = reverseLinkedList(head->next, tail, --n);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
    else {
        *tail = head->next;
        return head;
    }
}

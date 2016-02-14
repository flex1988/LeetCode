/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode* heven = malloc(sizeof(heven));
    struct ListNode *p, *q, *r;
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    heven = head->next;
    head->next = heven->next;
    p = heven->next;
    q = head;
    r = heven;
    bool isEven = false;
    while (p) {
        if (!isEven) {
            q->next = p;
            p = p->next;
            q = q->next;
        }
        else {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        isEven = !isEven;
    }
    r->next = NULL;
    q->next = heven;
    return head;
}

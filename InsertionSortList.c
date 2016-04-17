/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    struct ListNode* ret = NULL;
    struct ListNode* p = head;
    struct ListNode* r = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* h = p;
    while (p) {
        if (!ret) {
            struct ListNode* t = malloc(sizeof(t));
            t->val = p->val;
            ret = t;
            ret->next = NULL;
        }
        else {
            r = ret;
            while (r && r->val < p->val) {
                prev = r;
                r = r->next;
            }
            if (prev) {
                struct ListNode* x = prev->next;
                struct ListNode* t = malloc(sizeof(t));
                t->val = p->val;
                prev->next = t;
                t->next = x;
            }
            else {
                struct ListNode* t = malloc(sizeof(t));
                t->val = p->val;
                t->next = ret;
                ret = t;
            }
        }
        prev = NULL;
        p = p->next;
    }
    return ret;
}

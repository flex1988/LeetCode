/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;

    struct ListNode* high = NULL;
    struct ListNode* hhead = NULL;
    struct ListNode* p = head;
    struct ListNode* ret = NULL;
    struct ListNode* rhead = NULL;

    while (p) {
        if (p->val >= x) {
            if (!high) {
                high = p;
                hhead = p;
            }
            else {
                high->next = p;
                high = high->next;
            }
        }
        else {
            if (!ret) {
                ret = p;
                rhead = p;
            }
            else {
                ret->next = p;
                ret = ret->next;
            }
        }
        p = p->next;
    }
    if (!hhead) {
        return head;
    }
    else if (!rhead) {
        return hhead;
    }
    else {
        ret->next = hhead;
        high->next = NULL;
        return rhead;
    }
}

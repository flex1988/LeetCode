/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1)
        return l2;
    else if (!l2)
        return l1;

    int carry = 0;
    struct ListNode* ret = calloc(1, sizeof(struct ListNode));
    struct ListNode* q = ret;
    int tmp = l1->val + l2->val;
    if (tmp > 9) {
        ret->val = tmp - 10;
        carry = 1;
    }
    else {
        ret->val = tmp;
    }
    l1 = l1->next;
    l2 = l2->next;

    while (l1 && l2) {
        struct ListNode* n = calloc(1, sizeof(struct ListNode));
        tmp = l1->val + l2->val + carry;

        if (tmp > 9) {
            n->val = tmp - 10;
            carry = 1;
        }
        else {
            n->val = tmp;
            carry = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
        q->next = n;
        q = q->next;
    }

    while (l1 && !l2) {
        if (carry == 0) {
            q->next = l1;
            break;
        }
        struct ListNode* n = calloc(1, sizeof(struct ListNode));
        tmp = l1->val + 1;
        if (tmp > 9) {
            n->val = 0;
            carry = 1;
        }
        else {
            n->val = tmp;
            carry = 0;
        }
        l1 = l1->next;
        q->next = n;
        q = q->next;
    }

    while (!l1 && l2) {
        if (carry == 0) {
            q->next = l2;
            break;
        }

        struct ListNode* n = calloc(1, sizeof(struct ListNode));
        tmp = l2->val + 1;
        if (tmp > 9) {
            n->val = 0;
            carry = 1;
        }
        else {
            n->val = tmp;
            carry = 0;
        }
        l2 = l2->next;
        q->next = n;
        q = q->next;
    }

    if (carry > 0) {
        struct ListNode* n = calloc(1, sizeof(struct ListNode));
        n->val = 1;
        q->next = n;
    }

    return ret;
}

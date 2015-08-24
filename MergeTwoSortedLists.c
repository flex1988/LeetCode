struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1 || !l2)
        return !l1 ? l2 : l1;

    struct ListNode* head;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    }
    else {
        head = l2;
        l2 = l2->next;
    }
    struct ListNode* p = head;

    while (l1 || l2) {
        if (l2 && l1 && l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else if (l2 && l1 && l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        }
        else if (l1) {
            p->next = l1;
            l1 = l1->next;
        }
        else if (l2) {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    return head;
}

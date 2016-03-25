/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return NULL;
    if (head == head->next)
        return head;
    struct ListNode* slow = head;
    struct ListNode* fast = slow->next;
    struct ListNode* cir;
    struct ListNode* itor = head;
    bool isCycle = false;
    while (slow && fast && fast->next) {
        if (slow == fast) {
            isCycle = true;
            cir = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if (isCycle) {
        while (itor) {
            struct ListNode* t = cir;
            if (itor == t)
                return itor;
            cir = cir->next;
            while (cir != t) {
                if (cir == itor)
                    return itor;
                cir = cir->next;
            }
            itor = itor->next;
        }
    }
    return NULL;
}

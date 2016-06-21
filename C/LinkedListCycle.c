/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && slow) {
        if (fast->next && fast->next->next)
            fast = fast->next->next;
        else
            return false;
        if (slow->next)
            slow = slow->next;
        else
            return false;
        if (fast == slow)
            return true;
    }
    return false;
}

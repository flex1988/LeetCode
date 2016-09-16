/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        int sum = l1->val + l2->val;
        int carry = sum / 10;
        ListNode* l3 = new ListNode(sum % 10);
        l1 = l1->next;
        l2 = l2->next;
        ListNode* tail = l3;

        while (l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode* n = new ListNode(sum % 10);
            tail->next = n;
            tail = n;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return l3;
    }
};

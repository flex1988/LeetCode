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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (n == 0) return head;

        queue<ListNode*> queue;
        ListNode* p = head;
        while (p) {
            queue.push(p);
            p = p->next;
            if (queue.size() > n + 1) queue.pop();
        }
        if (queue.size() == n) {
            head = head->next;
            return head;
        } else {
            ListNode* item = queue.front();
            item->next = item->next->next;
            return head;
        }
    }
};

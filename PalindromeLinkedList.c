/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* Reverse(struct ListNode* h);

bool isPalindrome(struct ListNode* head)
{
    if (!head || !head->next)
        return true;
    struct ListNode* p = head;
    struct ListNode* q;
    int nums = 0;
    while (p) {
        nums++;
        p = p->next;
    }
    p = head;
    int mid = nums % 2 == 0 ? nums / 2 : nums / 2 + 1;
    int len = nums / 2;
    nums = 0;
    while (p) {
        if (nums == mid) {
            q = Reverse(p);
            break;
        }
        p = p->next;
        nums++;
    }
    p = head;
    for (; len > 0; len--) {
        printf("p:%d q:%d len:%d\n", p->val, q->val, len);
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}

struct ListNode* Reverse(struct ListNode* h)
{
    struct ListNode* q = h;
    if (!q)
        return NULL;
    struct ListNode* p = q->next;
    if (!p)
        return q;
    else {
        h = Reverse(p);
        p->next = q;
        q->next = NULL;
        return h;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge2Lists(struct ListNode* p, struct ListNode* q);
struct ListNode* mergeLists(struct ListNode** lists, int start, int end);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;
    return mergeLists(lists, 0, listsSize - 1);
}

struct ListNode* mergeLists(struct ListNode** lists, int start, int end)
{
    if (start == end)
        return lists[start];
    int pivot = (start + end) / 2;
    if (start == pivot)
        return merge2Lists(lists[start], lists[end]);
    struct ListNode* s;
    struct ListNode* e;
    s = mergeLists(lists, start, pivot);
    e = mergeLists(lists, pivot + 1, end);
    return merge2Lists(s, e);
}

struct ListNode* merge2Lists(struct ListNode* p, struct ListNode* q)
{
    struct ListNode* head;
    struct ListNode* r;

    if (p && !q)
        return p;
    else if (!p && q)
        return q;
    else if (!p && !q)
        return NULL;

    if (p->val > q->val) {
        head = q;
        q = q->next;
    }
    else {
        head = p;
        p = p->next;
    }
    r = head;

    while (p || q) {
        if (!p) {
            r->next = q;
            q = q->next;
        }
        else if (!q) {
            printf("%d\n", p->val);
            r->next = p;
            p = p->next;
        }
        else {
            if (p->val > q->val) {
                r->next = q;
                q = q->next;
            }
            else {
                r->next = p;
                p = p->next;
            }
        }
        r = r->next;
    }

    return head;
}

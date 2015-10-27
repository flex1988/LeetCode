/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    int lenA = lenList(headA);
    int lenB = lenList(headB);
    int diff = lenA - lenB;
    if (diff > 0) {
        while (diff--) {
            headA = headA->next;
        }
    }
    else {
        diff = -diff;
        while (diff--) {
            headB = headB->next;
        }
    }
    while (headA) {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int lenList(struct ListNode* root)
{
    int i = 0;
    while (root) {
        i++;
        root = root->next;
    }
    return i;
}

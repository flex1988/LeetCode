/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode* n = head;
        if (n->next == NULL)
            return n;
        ListNode* ret;
        vector<ListNode*> array;
        if (n->next->next == NULL) {
            if (n->val > n->next->val){
                n->next->next = n;
                ret = n->next;
                n->next = NULL;
                return ret;
            }else{
                return n;
            }
        } else {
            array = splitList(n);
            ListNode* left = sortList(array[0]);
            ListNode* right = sortList(array[1]);
            
            return joinList(left,right);
        }
    }
    
    vector<ListNode*> splitList(ListNode* n) {
        ListNode* quick;
        ListNode* slow;
        vector<ListNode*> ret(2);
        
        quick = slow = n;
        
        while(quick && quick->next && quick->next->next){
            slow = slow->next;
            quick = quick->next->next;
        }
        
        ret[0] = n;
        ret[1] = slow->next;
        slow->next = NULL;
        
        return ret;
    }
    
    ListNode* joinList(ListNode* left,ListNode* right){
        if(!left) return right;
        else if(!right) return left;
        
        ListNode* n = left;
        ListNode* m = right;
        ListNode* ret;
        if(n->val > m->val){
            ret = m;
            m = m->next;
        }else{
            ret = n;
            n = n->next;
        }
        ListNode* p = ret;
        
        while(n && m){
            if (n->val > m->val) {
                p->next = m;
                p = p->next;
                m = m->next;
            }
            else
            {
                p->next = n;
                p = p->next;
                n = n->next;
            }
        }
        
        if (n)
            p->next = n;
        if (m)
            p->next = m;
        return ret;
    }
};

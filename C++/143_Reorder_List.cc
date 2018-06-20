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
    void reorderList(ListNode* head) {
        if (!head) return;
        
        int sum = 0;
        ListNode* p = head;
        while(p) {
            q1_.push_back(p);
            p = p->next;
            sum++;
        }
        
        int t = sum/2;
        while(t--) {
            q2_.push_back(q1_.back());
            q1_.pop_back();
        }
        
        int idx1 = 0;
        int idx2 = 0;
        p = q1_[0];
        
        idx1++;
        while(idx1 < q1_.size() || idx2 < q2_.size()){
            if (idx2 < q2_.size()) {
                p->next = q2_[idx2++];
                p = p->next;
            }
            
            if (idx1 < q1_.size()) {
                p->next = q1_[idx1++];
                p = p->next;
            }
        }
        p->next = NULL;
    }
    
    vector<ListNode*> q1_;
    vector<ListNode*> q2_;
};

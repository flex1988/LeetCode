/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(!root)
            return;
        
        path_.push_back(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return path_.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* n = path_.back();
        TreeNode* p;
        path_.pop_back();
        
        while(n->left != NULL) {
            path_.push_back(n);
            p = n;
            n = n->left;
            p->left = NULL;
        }
        
        if (n->right) {
            path_.push_back(n->right);
            n->right = NULL;
        }
        
        return n->val;
    }
    
    vector<TreeNode*> path_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

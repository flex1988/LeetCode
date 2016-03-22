/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode* root)
{
    if (!root)
        return NULL;
    struct TreeLinkNode** stack = malloc(sizeof(struct TreeLinkNode*));
    int index = 0;
    stack[index++] = root;

    while (index) {
        struct TreeLinkNode** tstack = malloc(sizeof(struct TreeLinkNode*) * index * 2);
        int tindex = 0;
        for (int i = 0; i < index; i++) {
            if (i == index - 1)
                stack[i]->next = NULL;
            else
                stack[i]->next = stack[i + 1];
            if (stack[i]->left)
                tstack[tindex++] = stack[i]->left;
            if (stack[i]->right)
                tstack[tindex++] = stack[i]->right;
        }
        free(stack);
        stack = tstack;
        index = tindex;
    }
}

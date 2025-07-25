/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q)
        return 1;

    if((!p && q) || (p && !q))
        return 0;
    
    if(p->val != q->val)
        return 0;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
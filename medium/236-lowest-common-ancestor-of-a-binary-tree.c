/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
        return NULL;
    
    if(root->val == p->val || root->val == q->val)
        return root;
    
    struct TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
    struct TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

    if(leftAns != NULL && rightAns != NULL)
        return root;
    
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    
    else return NULL;
}
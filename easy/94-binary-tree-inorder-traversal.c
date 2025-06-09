/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inOrder(struct TreeNode* root, int* v, int* returnSize){
    if(root){
        inOrder(root->left, v, returnSize);
        v[*returnSize] = root->val;
        *returnSize += 1;
        inOrder(root->right, v, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* v = (int*) malloc(sizeof(int)*100);
    *returnSize = 0;
    inOrder(root, v, returnSize);
    return v;
}


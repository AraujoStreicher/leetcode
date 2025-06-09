/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void StoreNodes(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL) return;

        StoreNodes(root->left, v);
        v.push_back(root);
        StoreNodes(root->right, v);
    }

    TreeNode* balanceBSTutil(vector<TreeNode*> &v, int inicio, int fim){
        if(inicio > fim) return NULL;

        int meio = inicio + (fim - inicio) / 2;
        TreeNode* root = v[meio];

        root->left = balanceBSTutil(v, inicio, meio-1);
        root->right = balanceBSTutil(v, meio+1, fim);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> v;
        StoreNodes(root, v);

        return balanceBSTutil(v, 0, v.size()-1);
    }
};
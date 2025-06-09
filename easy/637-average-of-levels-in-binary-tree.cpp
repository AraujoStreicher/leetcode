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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); // Get the front element
                q.pop(); // Remove it from the queue
                
                sum += node->val; // Add its value to the sum
                
                if (node->left) q.push(node->left); // Add left child to the queue
                if (node->right) q.push(node->right); // Add right child to the queue
            }

            res.push_back(sum / levelSize); // Calculate the average for this level
        }

        return res;
    }
};
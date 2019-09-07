/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* root, int ds){
        if(!root) return ds - 1;
        int now = max(dfs(root->left, ds+1), dfs(root->right, ds+1));
        return now;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};
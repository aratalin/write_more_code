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
public:
    pair<int, int> dfs(TreeNode* root){
        if(!root) return make_pair(0, 0);
        int dp0 = 0, dp1 = root->val;
        
        pair<int, int>left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        dp1 += left.first + right.first;
        dp0 = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(dp0, dp1);
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
        
    }
};
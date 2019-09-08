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
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int val = root->val;
        int tmp_max = max(val, max(left+ val, right +val));
        ans = max(ans, max(tmp_max, val + left + right));
        return tmp_max;
    }
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};
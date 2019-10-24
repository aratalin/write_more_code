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
    int now, ans;
    int dfs(TreeNode* root, int k){
        if(!root) return 0;
        int son = 0;
        son += dfs(root->left, k);
        now ++;
        if(k == now){
            ans = root->val;
        }
        son += dfs(root->right, k);
        return son + 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        now = 0; ans = 0;
        int t = dfs(root, k);
        return ans;
    }
};
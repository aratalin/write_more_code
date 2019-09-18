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
    int dfs(TreeNode* root, int now){
        if (!root) return 0;
        int tmp = root->val;
        int right_sum = dfs(root->right, now);
        root->val += right_sum + now;
        now += right_sum;
        return right_sum + tmp + dfs(root->left, now + tmp);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int tp = dfs(root, 0);
        return root;
    }
};

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
    int ans;
    void dfs(TreeNode* root){
        if (!root) return;
        int tmp = root->val;
        dfs(root->right);
        root->val += ans;
        ans += tmp;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return root;
    }
};
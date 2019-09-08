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
    TreeNode* pre;
    void dfs(TreeNode* root){
        if(!root) return;
        pre->right = root;
        pre->left = NULL;
        pre = root;
        TreeNode* root_left = root->left;
        TreeNode* root_right = root->right;
        dfs(root_left);
        dfs(root_right);
    }
public:
   
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        pre = head;
        dfs(root);
        root = head->right;
    }
};
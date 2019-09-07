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
    bool dfs(TreeNode* left, TreeNode* right){
        if((left != NULL)  ^ (right != NULL)) return false;
        if((left == NULL) &&  (right == NULL)) return true;
        if (left->val != right->val) return false;
        if (!dfs(left->right, right->left)) return false;
        return dfs(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
    }
};
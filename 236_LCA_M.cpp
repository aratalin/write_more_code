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
    int build_ans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p) return 1;
        if(root == q) return 2;
        return 0;
    }
    TreeNode *ans;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return 0;
        int tmp = build_ans(root, p, q);
        if(ans) return 0;
        tmp |= dfs(root->left, p, q);
        if(tmp == 3) {
            ans = root;
            return 0;
        }
        tmp |= dfs(root->right, p, q);
        if(tmp == 3) {
            ans = root;
            return 0;
        }
        
        return tmp;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->ans = NULL;
        auto tmp = dfs(root, p, q);
        return ans;
    }
};
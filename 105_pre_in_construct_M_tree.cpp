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
    map<int, int> f;
    vector<int>ans;
    int now_idx;
    TreeNode* dfs(vector<int>&preorder, vector<int>&inorder, int in_left, int in_right){
        if(in_left == in_right) return NULL;
        int val = preorder[now_idx];
        now_idx ++;
        TreeNode *node = new TreeNode(val);
        int in_idx = f[val];
        node->left = dfs(preorder, inorder, in_left, in_idx);
        node->right = dfs(preorder, inorder, in_idx + 1, in_right);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            f[inorder[i]] = i;
        }
        now_idx = 0;
        return dfs(preorder, inorder, 0, preorder.size());
    }
};
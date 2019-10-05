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
    TreeNode* preNode, *node1, *node2;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(preNode){
            if(preNode->val > root->val){
                if(!node1) node1 = preNode;
                node2 = root;
            }
        }
        preNode = root;
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        preNode = NULL;
        dfs(root);
        swap(node1->val, node2->val);
        
    }
};
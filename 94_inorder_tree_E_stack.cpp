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
    vector<int>ans;
    void dfs(TreeNode* now){
        
        if (now->left != NULL) dfs(now->left);
        ans.push_back(now->val);
        if(now->right != NULL) dfs(now->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        //dfs(root);
        stack<TreeNode*> st;
        TreeNode* now = root;
        while(now != NULL || !st.empty()){
            while(now){
                st.push(now);
                now = now->left;
            }
            now = st.top(); st.pop();
            ans.push_back(now->val);
            now = now->right;
            
        }
        
        return ans;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int lay = -1;
        while(!q.empty()){
            pair<TreeNode*, int> now = q.front();   q.pop();
            if(ans.size() == now.second){
                lay = now.second;
                ans.push_back(vector<int>());
            }
            ans[lay].push_back(now.first->val);
            if(now.first->left != NULL){
                q.push(make_pair(now.first->left, lay + 1));
            }
            if(now.first->right != NULL){
                q.push(make_pair(now.first->right, lay + 1));
            }
        }
        return ans;
    }
};
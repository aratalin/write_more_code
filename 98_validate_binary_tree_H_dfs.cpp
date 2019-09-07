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
    pair<int, int> return_value(){
        return make_pair(INT_MAX, INT_MIN);
    }
    bool legal(pair<int, int> ans){
        return ans.first <= ans.second;
    }
    pair<int, int> dfs(TreeNode*root){
        int ans_min = root->val;
        int ans_max = root->val;
        if(root->left != NULL){
            pair<int, int> lf = dfs(root->left);
            if(!legal(lf)) return lf;
            if(lf.second >= root->val) return return_value();
            ans_min = lf.first;
        }
        if(root->right != NULL){
            pair<int, int> rf = dfs(root->right);
            if(!legal(rf)) return rf;
            if(rf.first <= root->val) return return_value();
            ans_max = rf.second;
        }
        return make_pair(ans_min, ans_max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left != NULL){
            pair<int, int> lf = dfs(root->left);
            if(!legal(lf)) return false;
            if(lf.second >= root->val) return false;
        }
            if(root->right!= NULL){
                pair<int, int> rf = dfs(root->right);
                if(!legal(rf)) return false;
                if(rf.first <= root->val) return false;
            }
        return true;
    }
};
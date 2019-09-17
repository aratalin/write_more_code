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
    unordered_map<int, int> f;
    int ans;
    void dfs(TreeNode* root, int sum, int dep){
        if(!root) return;
        dep += root->val;
        if(f.count(dep - sum)) ans += f[dep - sum];
        if(f.count(dep) == 0) f[dep] = 0;
        f[dep] = f[dep] + 1;
        dfs(root->left, sum, dep);
        dfs(root->right, sum, dep);
        f[dep] = f[dep] - 1;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;    
        f[0] = 1;
        dfs(root, sum, 0);
        return ans;
    }
};

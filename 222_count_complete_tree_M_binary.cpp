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
    
    bool judge(TreeNode* root, int num){
        vector<int> dir(32);
        int n = 0;
        while(num){
            dir[n] = num & 1;
            num >>= 1;  
            n++;
        }

        TreeNode* now = root;
        for(int i = n - 1; i >= 0; i--){
            if(!now) continue;
            if(dir[i]) {
                now = now->right;
            }else now = now->left;
            
        }
        return now != NULL;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* fake_root = new TreeNode(0);
        fake_root->right = root;
        int l = 0, r = INT_MAX;
        int ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(judge(fake_root, mid)){
                l = mid + 1;
                ans = mid;
            }else r = mid - 1;
        }
        delete fake_root;
        fake_root = NULL;
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kg, ans;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        kg--;
        if(kg==0){
            ans=root->val;
            return;
        }
        // cout<<root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        kg=k;
        inorder(root);
        return ans;
    }
};
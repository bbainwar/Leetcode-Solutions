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
    int value=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode* temp1=convertBST(root->right);
        root->val=root->val+value;
        value=root->val;
        TreeNode* temp2=convertBST(root->left);
        return root;
    }
};
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
    bool validBST(TreeNode* root, long minm, long maxm){
        if(root==NULL)
            return true;
        if(root->val<=minm || root->val>=maxm)
            return false;
        return validBST(root->left, minm, root->val) && validBST(root->right, root->val, maxm);
    }
    bool isValidBST(TreeNode* root) {
        long p231=pow(2,31);
        return validBST(root, -p231-1, p231);
    }
};
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
    int recur(TreeNode* node, int sum){
        if(node==NULL) return 0;
        sum=(sum*2)+node->val;
        if(node->left==NULL && node->right==NULL) return sum;
        return recur(node->left, sum)+recur(node->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return recur(root, 0);
    }
};
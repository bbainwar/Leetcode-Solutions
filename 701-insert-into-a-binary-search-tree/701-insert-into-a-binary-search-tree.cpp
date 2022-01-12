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
    void recur(TreeNode* root, int val){
        if(val<root->val){
            if(root->left==NULL){
                TreeNode* temp = new TreeNode();
                temp->val=val;
                root->left=temp;
                return;
            }
            recur(root->left, val);
        }
        else{
            if(root->right==NULL){
                TreeNode* temp = new TreeNode();
                temp->val=val;
                root->right=temp;
                return;
            }
            recur(root->right, val);
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp = new TreeNode();
            temp->val=val;
            return temp;
        }
        recur(root, val);
        return root;
    }
};
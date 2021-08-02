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
    vector<int> traversal;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        traversal.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balTree(TreeNode* root, int s, int e){
        if(s>e)
            return NULL;
        if(s==e){
            TreeNode* temp = new TreeNode(traversal[s]);
            root = temp;
            return root;
        }
        int mid=(s+e)/2;
        TreeNode* node = new TreeNode(traversal[mid]);
        node->val=traversal[mid];
        node->left=balTree(node->left, s, mid-1);
        node->right=balTree(node->right, mid+1, e);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return balTree(root, 0, traversal.size()-1);
    }
};
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
    int ans=INT_MIN;
    int solution(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            ans=max(ans, root->val);
            return root->val;
        }
        if(root->left==NULL){
            int rightMax=solution(root->right);
            int incNode=root->val+rightMax;
            ans=max(ans, max(rightMax, max(incNode, root->val)));
            return max(incNode, root->val);
        }
        if(root->right==NULL){
            int leftMax=solution(root->left);
            int incNode=root->val+leftMax;
            ans=max(ans, max(leftMax, max(incNode, root->val)));
            return max(incNode, root->val);
        }
        
        int leftMax=solution(root->left);
        int rightMax=solution(root->right);
        int incLeft=root->val+leftMax;
        int incRight=root->val+rightMax;
        int incLeftRight=leftMax+rightMax+root->val;
        ans=max(ans, max(leftMax, max(rightMax, max(incLeft, max(incRight, max(incLeftRight, root->val))))));
        return max(incLeft, max(incRight, root->val));
    }
    int maxPathSum(TreeNode* root) {
        int temp=solution(root);
        return ans;
    }
};
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
    int ans=0;
    int toNum(vector<int> arr){
        int count=0, ans=0;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i]==1)
                ans+=pow(2, count);
            count++;
        }
        return ans;
    }
    void recur(TreeNode* root, vector<int> arr){
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans+=toNum(arr);
            return;
        }
        if(root->left!=NULL){
            recur(root->left, arr);
        }
        if(root->right!=NULL){
            recur(root->right, arr);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        recur(root, {});
        return ans;
    }
};
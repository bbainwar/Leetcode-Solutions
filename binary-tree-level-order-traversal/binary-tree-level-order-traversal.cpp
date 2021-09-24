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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){return ans;}
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(q.empty()==false){
            pair<TreeNode*, int> temp=q.front();
            q.pop();
            
            if(ans.size()<=temp.second)
                ans.push_back({});
            ans[temp.second].push_back(temp.first->val);
            
            if(temp.first->left!=NULL)
                q.push(make_pair(temp.first->left, temp.second+1));
            if(temp.first->right!=NULL)
                q.push(make_pair(temp.first->right, temp.second+1));
            
        }
        
        return ans;
    }
};
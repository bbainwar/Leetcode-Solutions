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
    int levelDone=0;
    vector<int> ans;
    void solution(TreeNode* root, int level){
        if(root!=NULL){
            if(level>levelDone){
                ans.push_back(root->val);
                levelDone++;
            }
            solution(root->right, level+1);
            solution(root->left, level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        solution(root, 1);
        return ans;
    }
};
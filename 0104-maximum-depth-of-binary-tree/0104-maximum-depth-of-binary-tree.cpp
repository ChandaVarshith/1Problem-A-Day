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

    void visit(TreeNode* root,int level,int &ans){
        if(root==NULL){
            return;
        }
        if(level>ans){
            ans = level;
        }
        visit(root->left,level+1,ans);
        visit(root->right,level+1,ans);
        return;

    }

    int maxDepth(TreeNode* root) {
        int res=0;
        visit(root,1,res);
        return res;
    }
};
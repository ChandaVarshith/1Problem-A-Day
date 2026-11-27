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

    void same(TreeNode* node1,TreeNode* node2,bool &check){
        
        if(node1 ==NULL && node2 == NULL){
            return;
        }
        if((node1 ==NULL && node2!=NULL) || (node1 !=NULL && node2 == NULL)){
            check = false;
            return;
        }
        if(node1->val != node2->val) {
            check = false;
            return;    
        }

        
        
        
        same(node1->left,node2->left,check);
        same(node1->right,node2->right,check);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        same(p,q,ans);
        return ans;
    }
};
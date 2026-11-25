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
    void travel(vector<vector<int>> &res,TreeNode* root){
        if(root==nullptr) return;
        queue<TreeNode*>q;
        q.push(root);
        //BFS METHOD
        //First insert the root into the queue FIFO
        //In the same level store the element and pop the element from queue, store it 
        //pushback the current level elements to the  lvl vector
        //Now traverse the stored element left and right to find the lower level elements
        //then after one iteration: store the elements from lvl to push it to res
        //then iterate over all other elements "note: if no null pointer present"
        while(!q.empty()){
            int s = q.size();
            vector<int>lvl;
            
            for(int i=0;i<s;i++){
                TreeNode* node =q.front();
                q.pop();

                lvl.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        travel(res,root);
        return res;
    }
};
/****************************************************************************************
*  @author: kzvd4729                                         created: 07/11/2021 15:42                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 32 ms                                           memory_used: 24.3 MB                              
*  problem: https://leetcode.com/problems/binary-search-tree-iterator
****************************************************************************************/
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
class BSTIterator {
public:
        vector<int>val;int pt;
        void dfs(TreeNode* root)
    {
        if(root==NULL)return ;
                if(root->left)dfs(root->left);
                val.push_back(root->val);
                if(root->right)dfs(root->right);
            }
        BSTIterator(TreeNode* root) 
    {
        val.push_back(-1);
        dfs(root);
                pt=0;
    }
        int next() 
    {
        pt++;
        return val[pt];
    }
        bool hasNext() 
    {
        return pt<(int)val.size()-1;
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
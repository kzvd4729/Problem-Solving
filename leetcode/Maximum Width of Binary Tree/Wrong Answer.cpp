/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 02:04                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/maximum-width-of-binary-tree
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
class Solution {
public:
        int mx=1;
        void dfs(TreeNode* u, TreeNode* v,int diff)
    {
        mx=max(mx,diff);
                int next=(diff-2)*2;
                if(u->left)next+=2,u=u->left;
        else if(u->right)next++,u=u->right;
        else return ;
                if(v->right)next+=2,v=v->right;
        else if(v->left)next++,v=v->left;
        else return ;
                dfs(u,v,next);
    }
        int widthOfBinaryTree(TreeNode* root) 
    {
        if(root->left && root->right)
        {
            dfs(root->left, root->right,2);
        }
        if(root->left)widthOfBinaryTree(root->left);
        if(root->right)widthOfBinaryTree(root->right);
                return mx;
    }
};
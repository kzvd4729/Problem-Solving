/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 23:42                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 13.4 MB                              
*  problem: https://leetcode.com/problems/sum-of-left-leaves
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
        int sum=0;
        void dfs(TreeNode* root, int f)
    {
        if(root==NULL)return ;
                if(root->left==NULL && root->right==NULL && f)
            sum+=root->val;
                dfs(root->left, 1);
        dfs(root->right, 0);
    }
        int sumOfLeftLeaves(TreeNode* root) 
    {
        dfs(root, 0);
        return sum;
    }
};
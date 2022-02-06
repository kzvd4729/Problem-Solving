/****************************************************************************************
*  @author: kzvd4729                                         created: 06/26/2021 00:54                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 116 ms                                          memory_used: 86.5 MB                              
*  problem: https://leetcode.com/problems/count-good-nodes-in-binary-tree
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
    int goodNodes(TreeNode* root, int mx=-1000000000) 
    {
        if(root==NULL)return 0;
                int ret=0;
        if(mx<=root->val)ret++;
                mx=max(mx,root->val);
        return ret+goodNodes(root->left,mx)+goodNodes(root->right,mx);
    }
};
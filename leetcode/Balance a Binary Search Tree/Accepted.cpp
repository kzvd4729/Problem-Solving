/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 00:23                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 96 ms                                           memory_used: 47.1 MB                              
*  problem: https://leetcode.com/problems/balance-a-binary-search-tree
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
    void dfs(TreeNode* root, vector<TreeNode*>&v)
    {
        if(root==NULL)return;
                dfs(root->left,v);
        v.push_back(root);
        dfs(root->right,v);
    }
    TreeNode* construct(vector<TreeNode*>&v,int lo,int hi)
    {
        if(lo>hi)return NULL;
                int md=(lo+hi)/2;
            TreeNode* root= v[md];
                root->left=construct(v,lo,md-1);        
        root->right=construct(v,md+1,hi);
                return root;
            }
    TreeNode* balanceBST(TreeNode* root) 
    {
                    vector<TreeNode*>v;
        dfs(root,v);
                return construct(v,0,(int)v.size()-1);
            }
};
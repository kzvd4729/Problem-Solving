/****************************************************************************************
*  @author: kzvd4729                                         created: 06/08/2021 19:32                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 80 ms                                           memory_used: 25.8 MB                              
*  problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
TreeNode* dfs(vector<int>&pr,vector<int>&in,int l1,int r1,int l2,int r2)
{
    if(l1>r1)return NULL;
        TreeNode *root=new TreeNode(pr[l1]);
    int p=-1;
    for(int i=l2;i<=r2;i++)
    {
      if(in[i]==pr[l1])p=i;
    }
    root->left=dfs(pr,in,l1+1,l1+p-l2,l2,p-1);
    root->right=dfs(pr,in,l1+p-l2+1,r1,p+1,r2);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>&pre, vector<int>&in) 
    {
        return dfs(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};
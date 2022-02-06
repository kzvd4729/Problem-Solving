/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 15:43                         
*  solution_verdict: Runtime Error                           language: cpp                                     
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
        const int inf=1e9;
    vector<int>mn, mx;
    void dfs(TreeNode* root, int level, int num)
    {
        if((int)mn.size()==level)mn.push_back(inf);
        if((int)mx.size()==level)mx.push_back(-inf);
                mn[level]=min(mn[level], num);
        mx[level]=max(mx[level], num);
                        if(root->left)dfs(root->left, level+1, num*2);
        if(root->right)dfs(root->right, level+1, num*2+1);
            }
    int widthOfBinaryTree(TreeNode* root) 
    {
        dfs(root, 0, 0);
                int ans=-inf;
        for(int i=0;i<(int)mn.size();i++)ans=max(ans,mx[i]-mn[i]+1);
                return ans;
    }
};
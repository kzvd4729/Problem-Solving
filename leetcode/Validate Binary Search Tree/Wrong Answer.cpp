/****************************************************************************************
*  @author: kzvd4729                                         created: 04/12/2021 23:43                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/validate-binary-search-tree
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
        bool dfs(TreeNode* root,long long lo,long long hi)
    {
        if(root != NULL)
        {
            if(root->val < lo || root->val >hi)return false;
                        TreeNode *left= root->left;
            if((left != NULL) && (left->val > root->val) )return false;
                        TreeNode *right= root->right;
            if((right != NULL) && (right->val < root->val) )return false;
                        return (dfs(left,lo,root->val)&dfs(right,root->val,hi));
        }
                return true;
    }
        bool isValidBST(TreeNode* root) {
                long long inf=1LL*1000000000*1000000000;
        return dfs(root,-inf,inf);
            }
};
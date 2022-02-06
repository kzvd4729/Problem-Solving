/****************************************************************************************
*  @author: kzvd4729                                         created: 04/12/2021 23:33                         
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
        bool isValidBST(TreeNode* root) {
                if(root != NULL)
        {
            TreeNode *left= root->left;
            if((left != NULL) && (left->val > root->val) )return false;
                        TreeNode *right= root->right;
            if((right != NULL) && (right->val < root->val) )return false;
                        return (isValidBST(left)&isValidBST(right));
        }
                return true;
            }
};
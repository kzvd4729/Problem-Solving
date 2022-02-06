/****************************************************************************************
*  @author: kzvd4729                                         created: 04/12/2021 23:28                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 44 ms                                           memory_used: 34.9 MB                              
*  problem: https://leetcode.com/problems/search-in-a-binary-search-tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
                while(root != nullptr)
        {
            if(root->val == val)break;
            if(val<=root->val)root=root->left;
            else root=root->right;
        }
        return root;
    }
};
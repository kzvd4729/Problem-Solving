/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 20:52                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 17.4 MB                              
*  problem: https://leetcode.com/problems/trim-a-binary-search-tree
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
        pair<TreeNode*,TreeNode*>splitByValue(TreeNode* root,int val)
    {
        if(root==NULL)return {NULL,NULL};
                if(root->val <= val)
        {
            pair<TreeNode*,TreeNode*>p=splitByValue(root->right,val);
            root->right=p.first;
                        return {root,p.second};
        }
        else
        {
            pair<TreeNode*,TreeNode*>p=splitByValue(root->left,val);
            root->left=p.second;
                        return {p.first,root};
        }
    }
        TreeNode* trimBST(TreeNode* root, int low, int high) {
                pair<TreeNode*,TreeNode*>p=splitByValue(root,low-1);
                root=p.second;
                p=splitByValue(root,high);
                return p.first;
            }
};
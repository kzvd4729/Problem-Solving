/****************************************************************************************
*  @author: kzvd4729                                         created: 07/11/2021 16:00                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 60 ms                                           memory_used: 24.1 MB                              
*  problem: https://leetcode.com/problems/binary-search-tree-iterator
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
class BSTIterator {
public:
        stack<TreeNode*>s;
        BSTIterator(TreeNode* root) 
    {
        if(root==NULL)return ;
                s.push(root);
                while(s.top()->left)
        {
            s.push(s.top()->left);
        }
    }
        int next() 
    {
        int ret=s.top()->val;
                TreeNode* nx=s.top()->right;
        s.pop();
                while(nx!=NULL)
        {
            s.push(nx);
            nx=nx->left;
        }
                return ret;
    }
        bool hasNext() 
    {
        return (bool)s.size();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
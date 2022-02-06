/****************************************************************************************
*  @author: kzvd4729                                         created: 06/08/2021 19:45                         
*  solution_verdict: Runtime Error                           language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
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
const int sz=1e5;//more size better, normaly 2*(number of insert) works fine
int key[sz+2],val[sz+2];//can be any data type
int buf[sz+2],id;
//static inline int h(int x){return((x^179)*7LL)%sz;}
static inline int h(int x){return(((x^179)*7LL)%sz+sz)%sz;}//negtive value
void init()
{
  memset(key,-1,sizeof key);//-1 is invalid
}
void add(int x,int y)//assign
{
  int k=h(x);
  while(key[k]!=-1&&key[k]!=x)k=(k+1)%sz;//first non-taken index
  key[k]=x,val[k]=y;
  //buf[++id]=k;
}
int get(int x)
{
  for(int k=h(x);key[k]!=-1;k=(k+1)%sz)
    if(key[k]==x)return val[k];
  return -1;
}
void clear()
{
  for(int i=1;i<=id;i++)key[buf[i]]=-1,val[buf[i]]=0;
  id=0;
}
TreeNode* dfs(vector<int>&pr,vector<int>&in,int l1,int r1,int l2,int r2)
{
    if(l1>r1)return NULL;
        TreeNode *root=new TreeNode(pr[l1]);
    int p=-1;
    p=get(pr[l1]);
    root->left=dfs(pr,in,l1+1,l1+p-l2,l2,p-1);
    root->right=dfs(pr,in,l1+p-l2+1,r1,p+1,r2);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>&pre, vector<int>&in) 
    {
        init();clear();
        for(int i=0;i<(int)in.size();i++)add(in[i],i);
        return dfs(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};
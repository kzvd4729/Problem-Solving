/****************************************************************************************
*  @author: kzvd4729                                         created: 06/16/2021 19:46                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 15.6 MB                              
*  problem: https://leetcode.com/problems/generate-parentheses
****************************************************************************************/
class Solution 
{
public:
    void dfs(string s,int n,int bl,vector<string>&ret)
    {
        if(n==0)
        {
            ret.push_back(s);
            return ;
        }
        if(bl+1<=n-1)
        {
            s.push_back('(');
            dfs(s,n-1,bl+1,ret);s.pop_back();
        }
        if(bl>0)
        {
            s.push_back(')');
            dfs(s,n-1,bl-1,ret);s.pop_back();
        }
    }
        vector<string> generateParenthesis(int n) 
    {
        vector<string>ret;
        string s;dfs(s,n+n,0,ret);
        return ret;
    }
};
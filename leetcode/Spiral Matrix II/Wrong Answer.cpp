/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 20:24                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/spiral-matrix-ii
****************************************************************************************/
class Solution {
public:
        vector<vector<int> >v;
    int now=0;
        void dfs(int r,int c,int n)
    {
        if(v[r][c])return ;
        v[r][c]=++now;
                if(c+1<n)dfs(r,c+1,n);
        if(r+1<n)dfs(r+1,c,n);
                if(c-1>=0)dfs(r,c-1,n);
        if(r-1>=0)dfs(r-1,c,n);
    }
            vector<vector<int>> generateMatrix(int n) 
    {
        v.resize(n);
        for(int i=0;i<n;i++)v[i].resize(n,0);
                dfs(0,0,n);
                return v;
    }
};
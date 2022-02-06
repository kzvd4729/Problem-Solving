/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 20:36                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 0 ms                                            memory_used: 6.6 MB                               
*  problem: https://leetcode.com/problems/spiral-matrix-ii
****************************************************************************************/
class Solution {
public:
        vector<vector<int> >v;
    int now=0;
        void dfs(int r,int c,int n)
    {   
        int l;
        if(c+1<n && v[r][c+1]==0)
        {
            for(int j=c+1;j<n;j++)
            {
                if(v[r][j]==0)v[r][j]=++now,l=j;
                else break;
            }
            dfs(r,l,n);
        }
        else if(r+1<n && v[r+1][c]==0)
        {
            for(int i=r+1;i<n;i++)
            {
                if(v[i][c]==0)v[i][c]=++now,l=i;
                else break;
            }
            dfs(l,c,n);
        }
                else if(c-1>=0 && v[r][c-1]==0)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(v[r][j]==0)v[r][j]=++now,l=j;
                else break;
            }
            dfs(r,l,n);
        }
        else if(r-1>=0 && v[r-1][c]==0)
        {
            for(int i=r-1;i>=0;i--)
            {
                if(v[i][c]==0)v[i][c]=++now,l=i;
                else break;
            }
            dfs(l,c,n);
        }
            }
            vector<vector<int>> generateMatrix(int n) 
    {
        v.resize(n);
        for(int i=0;i<n;i++)v[i].resize(n,0);
                v[0][0]=++now;
        dfs(0,0,n);
                return v;
    }
};
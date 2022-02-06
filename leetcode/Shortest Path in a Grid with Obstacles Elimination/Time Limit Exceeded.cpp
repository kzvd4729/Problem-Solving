/****************************************************************************************
*  @author: kzvd4729                                         created: 12/20/2019 23:08                         
*  solution_verdict: Time Limit Exceeded                     language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination
****************************************************************************************/
int ds[40+2][40+2][40*40+4];
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size(),m=grid[0].size();
        int d=n*m;
                for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                for(int k=0;k<=d;k++)ds[i][j][k]=1e9;
        }
        queue<vector<int> >q;
        if(grid[0][0]==0)ds[0][0][0]=0,q.push({0,0,0});
        else ds[0][0][1]=0,q.push({0,0,1});
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(q.size())
        {
            vector<int>v=q.front();q.pop();
            for(int i=0;i<4;i++)
            {
                int ii=v[0]+dx[i],jj=v[1]+dy[i];
                if(ii>=0&&jj>=0&&ii<n&&jj<m)
                {
                    int dd=v[2];if(grid[ii][jj]==1)dd++;
                    if(ds[v[0]][v[1]][v[2]]+1<ds[ii][jj][dd])
                    {
                        ds[ii][jj][dd]=ds[v[0]][v[1]][v[2]]+1;
                        q.push({ii,jj,dd});
                    }
                }
            }
        }
        int mn=1e9;
        for(int i=0;i<=k;i++)mn=min(mn,ds[n-1][m-1][i]);
        if(mn==1e9)mn=-1;return mn;
    }
};
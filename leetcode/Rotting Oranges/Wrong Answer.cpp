/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 20:18                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/rotting-oranges
****************************************************************************************/
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
class Solution 
{
public:
    const int inf=1e9;
        int orangesRotting(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
                vector<vector<int> >d(n,vector<int>(m,0));
                queue<pair<int,int> >q;
                for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==2)q.push({i,j}),d[i][j]=0;
                else d[i][j]=inf;
            }
        }
                        while((int)q.size())
        {
            pair<int,int>p=q.front();q.pop();
                        for(int i=0;i<4;i++)
            {
                int u=p.first+dx[i];
                int v=p.second+dy[i];
                                if((u>=0) && (u<n) && (v>=0) && (v<m) && (d[p.first][p.second]+1<d[u][v]) && d[u][v])
                {
                    d[u][v]=d[p.first][p.second]+1;
                    q.push({u,v});
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)if(a[i][j])mx=max(mx,d[i][j]);
        }
        if(mx==inf)mx=-1;
                return mx;
    }
};
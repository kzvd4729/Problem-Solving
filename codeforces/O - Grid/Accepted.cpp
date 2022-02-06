/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/15/2017 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 6300 KB                              
*  problem: https://codeforces.com/gym/100819/problem/O
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,mat[505][505],vis[505][505],dis[505][505];
string s;
struct dat
{
    long r;
    long c;
    long v;
};
queue<dat>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1; i<=n; i++)
    {
        cin>>s;
        for(long j=1;j<=s.size();j++)
        {
            mat[i][j]=s[j-1]-'0';
        }
    }
    dat x,z;
    x.r=1;
    x.c=1;
    x.v=mat[1][1];
    q.push(x);
     while(q.size())
    {
        z=q.front();
        q.pop();
        long row=z.r;
        long col=z.c;
        long val=z.v;
        if(col+val<=m)
        {
            if(vis[row][col+val]==0)
            {
                q.push({row,col+val,mat[row][col+val]});
                vis[row][col+val]=1;
                dis[row][col+val]=dis[row][col]+1;
            }
        }
        if(col-val>=1)
        {
            if(vis[row][col-val]==0)
            {
                q.push({row,col-val,mat[row][col-val]});
                vis[row][col-val]=1;
                dis[row][col-val]=dis[row][col]+1;
            }
        }
         if(row+val<=n)
        {
            if(vis[row+val][col]==0)
            {
                q.push({row+val,col,mat[row+val][col]});
                vis[row+val][col]=1;
                dis[row+val][col]=dis[row][col]+1;
            }
        }
        if(row-val>=1)
        {
            if(vis[row-val][col]==0)
            {
                q.push({row-val,col,mat[row-val][col]});
                vis[row-val][col]=1;
                dis[row-val][col]=dis[row][col]+1;
            }
        }
     }
    if(dis[n][m]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<dis[n][m]<<endl;
     return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2017 01:14                        
*  solution_verdict: Wrong answer on test 49                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 26800 KB                             
*  problem: https://codeforces.com/contest/877/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,s1,s2,e1,e2;
char mat[1002][1002];
string x;
queue<pair<long,long> >q;
long dis[1003][1003],vis[1003][1003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        for(long j=1;j<=m;j++)
        {
            mat[i][j]=x[j-1];
        }
    }
     cin>>s1>>s2>>e1>>e2;
    for(long i=1;i<=1000;i++)
    {
        for(long j=1;j<=1000;j++)dis[i][j]=999999999;
    }
    q.push({s1,s2});
    dis[s1][s2]=0;
    vis[s1][s2]=1;
     while(q.size())
    {
        if(vis[e1][e2]==1)break;
        long a=q.front().first;
        long b=q.front().second;
        q.pop();
        for(long j=1;j<=k;j++)
        {
            if(j+b>m)break;
            if(mat[a][j+b]=='#'||vis[a][j+b]==1)break;
            dis[a][j+b]=min(dis[a][j+b],dis[a][b]+1);
            q.push({a,j+b});
            vis[a][j+b]=1;
        }
        for(long j=1;j<=k;j++)
        {
            if(j+a>n)break;
            if(mat[a+j][b]=='#'||vis[a+j][b]==1)break;
            dis[a+j][b]=min(dis[a+j][b],dis[a][b]+1);
            q.push({a+j,b});
            vis[a+j][b]=1;
        }
        for(long j=1;j<=k;j++)
        {
            if(b-j<1)break;
            if(mat[a][b-j]=='#'||vis[a][b-j]==1)break;
            dis[a][b-j]=min(dis[a][b-j],dis[a][b]+1);
            q.push({a,b-j});
            vis[a][b-j]=1;
        }
        for(long j=1;j<=k;j++)
        {
            if(a-j<1)break;
            if(mat[a-j][b]=='#'||vis[a-j][b]==1)break;
            dis[a-j][b]=min(dis[a-j][b],dis[a][b]+1);
            q.push({a-j,b});
            vis[a-j][b]=1;
        }
     }
    if(dis[e1][e2]==999999999)dis[e1][e2]=-1;
    cout<<dis[e1][e2]<<endl;
     return 0;
}
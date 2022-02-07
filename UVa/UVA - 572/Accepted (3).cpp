/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 00:20:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-572
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dr[]={0,1,1,1,0,-1,-1,-1};
long dc[]={1,1,0,-1,-1,-1,0,1};
long vis[102][102],n,m;
string s[102];
void dfs(long r,long c)
{
    vis[r][c]=1;
    for(long i=0;i<8;i++)
    {
        long x=r+dr[i];
        long y=c+dc[i];
        if(x<0||y<0||x>=n||y>=m)continue;
        if(vis[x][y])continue;
        if(s[x][y]=='@')dfs(x,y);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        for(long i=0;i<n;i++)
        {
            cin>>s[i];
        }
        long ans=0;
        memset(vis,0,sizeof(vis));
        for(long i=0;i<n;i++)
        {
            for(long j=0;j<m;j++)
            {
                if(s[i][j]=='@'&&vis[i][j]==0)
                {
                    ans++;
                    dfs(i,j);
                    ///cout<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
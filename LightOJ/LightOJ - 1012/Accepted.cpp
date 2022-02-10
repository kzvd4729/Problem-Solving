/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-14 21:34:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 32                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1012
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,w,h,cnt,vis[22][22],tc;
long dr[]={0,0,1,-1};
long dc[]={1,-1,0,0};
string s[22];
void dfs(long r,long c)
{
    cnt++;
    vis[r][c]=1;
    for(long i=0;i<4;i++)
    {
        long x=r+dr[i];
        long y=c+dc[i];
        if(x<0||y<0||x>=h||y>=w)continue;
        if(s[x][y]=='#'||vis[x][y]==1||s[x][y]=='@')continue;
        dfs(x,y);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>w>>h;
        for(long i=0;i<h;i++)cin>>s[i];
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(long i=0;i<h;i++)
        {
            for(long j=0;j<w;j++)
            {
                if(s[i][j]=='@')dfs(i,j);
            }
        }
        cout<<"Case "<<++tc<<": "<<cnt<<endl;
    }

    return 0;
}
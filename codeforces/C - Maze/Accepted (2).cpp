/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/11/2018 20:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 18000 KB                             
*  problem: https://codeforces.com/contest/378/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,ri,rj,k;
char mat[502][502],vis[502][502];
long dr[]={0,0,1,-1};
long dc[]={1,-1,0,0};
string s;
void dfs(long ri,long rj)
{
    vis[ri][rj]=1;
    for(long i=0;i<4;i++)
    {
        long xx,yy;
        xx=ri+dr[i];
        yy=rj+dc[i];
        if(xx<1||xx>n||yy<1||yy>m)continue;
        if(vis[xx][yy]||mat[xx][yy]=='#')continue;
        dfs(xx,yy);
    }
    if(k)mat[ri][rj]='X',k--;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>s;
        for(long j=1;j<=m;j++)
        {
            mat[i][j]=s[j-1];
            if(mat[i][j]=='.')ri=i,rj=j;
        }
    }
    dfs(ri,rj);
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
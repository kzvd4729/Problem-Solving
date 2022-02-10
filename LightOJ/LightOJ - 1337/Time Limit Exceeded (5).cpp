/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-26 20:57:01                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1337
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,x,y,tc,n,m,q,cnt,c,cnt2,ans[502*502],vis[502][502];
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
char mat[502][502],s[502];
void dfs(int r,int c)
{
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx=r+dr[i];
        yy=c+dc[i];
        if(xx>m||xx<1||yy>n||yy<1)continue;
        if(vis[xx][yy]||mat[xx][yy]=='#')continue;
        if(mat[xx][yy]=='C')cnt2++;
        vis[xx][yy]=cnt;
        dfs(xx,yy);
    }
}
int main()
{
    ///ofstream cout("out.txt");
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld",&m,&n,&q);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s);
            for(int j=1;j<=n;j++)
            {
                mat[i][j]=s[j-1];
            }
        }
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        cnt=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[i][j]||mat[i][j]=='#')continue;
                cnt++;
                vis[i][j]=cnt;
                cnt2=0;
                dfs(i,j);
                ans[cnt]=cnt2;
            }
        }
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            scanf("%ld%ld",&x,&y);
            cout<<ans[vis[x][y]]<<endl;
        }
    }
    return 0;
}
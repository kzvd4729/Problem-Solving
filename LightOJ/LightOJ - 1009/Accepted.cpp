/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-14 18:39:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 196                                        memory_used (MB): 4.6                             
*  problem: https://vjudge.net/problem/LightOJ-1009
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,u,v,lev[3],vis[20002],ans,tc=0;
vector<int>vv[20002];
void mem(void)
{
    for(int i=1;i<=20000;i++)
    {
        vis[i]=0;
        vv[i].clear();
    }
}
void dfs(int n,int p,int h)
{
    vis[n]=1;
    lev[h%2]++;
    for(int x=0;x<vv[n].size();x++)
    {
        if(vv[n][x]!=p&&vis[vv[n][x]]==0)dfs(vv[n][x],n,h+1);
    }
    /*for(auto x:vv[n])
    {
        if(x!=p&&vis[x]==0)dfs(x,n,h+1);
    }*/
}
int main()
{
    ///ofstream cout("ottt.txt");
    scanf("%d",&t);
    while(t--)
    {
        mem();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&u);
            scanf("%d",&v);
            vv[v].push_back(u);
            vv[u].push_back(v);
        }
        ans=0;
        for(int i=1;i<=20000;i++)
        {
            if(vis[i]==0&&vv[i].size())
            {
                lev[0]=0;
                lev[1]=0;
                dfs(i,-1,0);
                ans+=max(lev[0],lev[1]);
            }
        }
        ///Case 1: 2
        printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}
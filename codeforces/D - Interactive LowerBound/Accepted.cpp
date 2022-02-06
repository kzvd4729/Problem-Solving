/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 10:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int v,id,n,s,x,vl,ii,nx,vis[200002];
int main()
{
    scanf("%d%d%d",&n,&s,&x);
    printf("? %d\n",s);
    fflush(stdout);
    scanf("%d%d",&v,&id);
    vl=v;
    nx=id;
    for(int i=1;i<=1000;i++)
    {
        ii=((i*1000000009)%n+n+n+7)%n+1;
        if(vis[ii]==1)continue;
        vis[ii]=1;
        printf("? %d\n",ii);
        fflush(stdout);
        scanf("%d%d",&v,&id);
        if(v<=x&&v>=vl)
        {
            vl=v;
            nx=id;
        }
     }
    while(true)
    {
        if(vl>=x)break;
        if(nx==-1)break;
        printf("? %d\n",nx);
        fflush(stdout);
        scanf("%d%d",&v,&id);
        vl=v;
        nx=id;
    }
    if(vl>=x)printf("! %d\n",vl);
    else printf("! -1\n");
    fflush(stdout);
    return 0;
}
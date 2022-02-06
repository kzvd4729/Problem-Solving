/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 09:38                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int v,id,n,s,x,vl,nx,q[1002];
int main()
{
    scanf("%d%d%d",&n,&s,&x);
    for(int i=1;i<=1000;i++)
    {
        q[i]=rand()%n;
    }
    printf("? %d\n",s);
    fflush(stdout);
    scanf("%d%d",&v,&id);
    vl=v;
    nx=id;
    for(int i=1;i<=1000;i++)
    {
        printf("? %d\n",q[i]);
        fflush(stdout);
        scanf("%d%d",&v,&id);
        if(v<=x&&v>vl)
        {
            vl=v;
            nx=id;
        }
     }
    while(true)
    {
        if(nx==-1)break;
        if(vl>=x)break;
        printf("? %d\n",nx);
        fflush(stdout);
        scanf("%d%d",&vl,&nx);
    }
    if(vl>=x)printf("! %d\n",vl);
    else printf("! -1\n");
    fflush(stdout);
    return 0;
}
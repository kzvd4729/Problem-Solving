/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/11/2017 12:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/796/problem/B
****************************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,h,k,hole[1000006],p,q,pos,i;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1; i<=m; i++)
    {
        scanf("%d",&h);
        hole[h]=1;
    }
    pos=1;
    int f=0;
    for(i=1; i<=k; i++)
    {
        scanf("%d%d",&p,&q);
        if(hole[pos]==1)f=1;
        if(f==0)
        {
            if(p==pos)pos=q;
            else if(q==pos)pos=p;
            if(hole[pos]==1)f=1;
        }
     }
    printf("%d\n",pos);
    return 0;
}
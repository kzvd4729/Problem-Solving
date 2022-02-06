/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 10:29                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int v,id,n,s,x,vl=-1,nx,q[1002];
int main()
{
    scanf("%d%d%d",&n,&s,&x);
    for(int i=1;i<=1000;i++)
    {
        q[i]=((((rand()%n)*i*i)%n)+n+n+7)%n;
    }
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
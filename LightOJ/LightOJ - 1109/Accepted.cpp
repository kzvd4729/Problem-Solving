/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-11 10:51:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1109
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct vd
{
    int a;
    int b;
}c[1004];
bool cmp(vd A,vd B)
{
    if(A.b!=B.b)return A.b<B.b;
    return A.a>B.a;
}
void NOD(void)
{
    memset(c,0,sizeof(c));
    int i,j;
    for(i=1;i<=1000;i++)
    {
        c[i].a=i;
        for(j=i;j<=1000;j=j+i)
        {
            c[j].b++;
        }
    }
    sort(c+1,c+1001,cmp);
}
int main()
{
    NOD();
    int t,n,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++tc,c[n].a);
    }
    return 0;
}
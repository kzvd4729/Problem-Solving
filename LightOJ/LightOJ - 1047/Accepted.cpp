/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-06 14:44:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1047
****************************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x,y,z,xx,yy,zz,xxx,yyy,zzz,t,tc,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&x,&y,&z);
        xx=x;
        yy=y;
        zz=z;
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            xxx=x+min(yy,zz);
            yyy=y+min(xx,zz);
            zzz=z+min(xx,yy);
            xx=xxx,yy=yyy,zz=zzz;
        }
        printf("Case %d: %d\n",++tc,min(xx,min(yy,zz)));
    }
    return 0;
}
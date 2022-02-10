/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 22:47:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,a,b,c,d,x,y,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d",&n);
        printf("Case %d:\n",++tc);
        while(n--)
        {
            scanf("%d%d",&x,&y);
            if(x<a||x>c||y<b||y>d)printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
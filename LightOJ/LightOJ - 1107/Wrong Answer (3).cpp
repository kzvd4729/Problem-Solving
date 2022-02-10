/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 22:43:25                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int tc, a, b, c, d, x, y, n, t;
int main()
{
    scanf("%ld",&t);
    while (t--)
    {
        scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
        scanf("%ld",&n);
        printf("Case %d:\n",++tc);
        while (n--)
        {
            scanf("%ld%ld",&x,&y);
            if (a <= x&&x <= c&&b <= y&&y <= d)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
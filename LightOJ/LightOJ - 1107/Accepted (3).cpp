/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 22:42:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 188                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int tc, a, b, c, d, x, y, n, t;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        cin >> n;
        printf("Case %d:\n",++tc);
        while (n--)
        {
            cin >> x >> y;
            if ((a <= x&&x <= c&&b <= y&&y <= d))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
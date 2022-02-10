/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-16 09:18:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 8                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1225
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,tc,x1,x2,x,r;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&x1);
        x=x1;
        x2=0;
        while(x)
        {
            r=x%10;
            x2=(x2*10)+r;
            x=x/10;
        }
        if(x1==x2)printf("Case %lld: Yes\n",++tc);
        else printf("Case %lld: No\n",++tc);
    }

    return 0;
}
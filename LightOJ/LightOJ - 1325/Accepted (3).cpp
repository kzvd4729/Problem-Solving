/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-01 10:59:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 554                                        memory_used (MB): 2.7                             
*  problem: https://vjudge.net/problem/LightOJ-1325
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long solve (long a, long b, long m) 
{
    long n = sqrt (m + .0) + 1;
    long an = 1;
    for (long i=0; i<n; ++i)
        an = (an * a) % m;
    map<long,long> vals;
    for (long i=1, cur=an; i<=n; ++i) 
    {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }
    long ret=1e18;
    for (long i=0, cur=b; i<=n; ++i) 
    {
        if (vals.count(cur)) {
            long ans = vals[cur] * n - i;
            if (ans < m)
                ret=min(ret,ans);
        }
        cur = (cur * a) % m;
    }
    return ret;
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int a,b;scanf("%d%d",&a,&b);
    printf("Case %d: %lld\n",++tc,solve(a,b,100000007));
  }
  return 0;
}
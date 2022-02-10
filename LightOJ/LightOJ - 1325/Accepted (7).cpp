/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-01 10:53:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1321                                       memory_used (MB): 2.7                             
*  problem: https://vjudge.net/problem/LightOJ-1325
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long powmod (long a, long b, long m) 
{
    long res = 1;
    while (b > 0)
        if (b & 1) {
            res = (res * a) % m;
            --b;
        }
        else {
            a = (a * a) % m;
            b >>= 1;
        }
    return res % m;
}
long solve (long a, long b, long m) 
{
    long n = (long) sqrt (m + .0) + 1;
    map<long,long> vals;long ret=1e18;
    for (long i=n; i>=1; --i)
        vals[ powmod (a, i * n, m) ] = i;
    for (long i=0; i<=n; ++i) {
        long cur = (powmod (a, i, m) * b) % m;
        if (vals.count(cur)) {
            long ans = vals[cur] * n - i;
            if (ans < m)
                ret=min(ret,ans);
        }
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
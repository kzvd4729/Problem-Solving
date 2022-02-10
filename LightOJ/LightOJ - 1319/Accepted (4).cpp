/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-26 15:42:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 148                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1319
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const long long N = 20;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
long long testCases;
long long t;
long long a[N], n[N], ans, lcm;
int main()
{
  int tc=0,ts;cin>>ts;
  while(ts--)
  {
    cin >> t;
    for(long long i = 1; i <= t; i++) cin >> n[i] >> a[i], normalize(a[i], n[i]);
    ans = a[1];
    lcm = n[1];
    for(long long i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcm, n[i]);
        long long x1 = pom.x;
        long long d = pom.d;
        if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
        lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}
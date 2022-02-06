/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 17:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101550/problem/D
****************************************************************************************/
#include <bits/stdc++.h>
#define int long long 
using namespace std;
 typedef long long LL;
   int dp[400], m[400], c[400];
 int32_t main() {
        int n, mx = 100; cin >> n;
        dp[0] = c[0] = 100;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            for(int j = 0; j < i; j++) dp[i] = max(dp[i], m[j] * x + c[j]);
            int k = min(100000LL, mx / x), p = mx - k * x;
           // cout << mx << " " << k << " " << p << endl;
            m[i] = k;
            c[i] = p;
            mx = max(mx, dp[i]);
        }
         cout << mx << endl;
}
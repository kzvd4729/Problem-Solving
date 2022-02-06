/****************************************************************************************
*  @author: jU_zQxRvd: iShibly, mh755628, kzvd4729           created: Apr/04/2021 14:40                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 17000 KB                             
*  problem: https://codeforces.com/contest/1510/problem/D
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
  //#define int long long 
  const int N = 1e5 + 10;
 int a[N], n, d;
 using ld = long double;
 ld dp[N][10];
 bool vis[N][10];
 ld f(int i, int mod) {
    if(i > n) {
        return mod == d ? 0 : -1e9;
    }
     if(vis[i][mod])
        return dp[i][mod];
    vis[i][mod] = true;
     ld x = log(a[i]);
     ld res = max(f(i + 1, mod), x + f(i + 1, (mod * a[i]) % 10));
    return dp[i][mod] = res;
}
  vector <int> ans;
 void print(int i, int mod) {
    if(i > n) 
        return;
     ld x = log(a[i]);
     if(f(i, mod) == f(i + 1, mod)) {
        print(i + 1, mod);
    } else {
        ans.push_back(a[i]);
        print(i + 1, (mod * a[i]) % 10);
    }
}
 template <typename T> void print(vector <T> &v) {
    for(int i = 0; i < v.size(); ++i) 
        cout << v[i] << " \n"[i + 1 == v.size()];
}
 int32_t main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
     if(f(1, 1) < 0) {
        cout << -1 << endl;
        return 0;
    }
     print(1, 1);
     cout << ans.size() << endl;
    print(ans);
 }
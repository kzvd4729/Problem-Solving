/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 14:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 9500 KB                              
*  problem: https://codeforces.com/contest/690/problem/C2
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 const int N = 100001;
 vector <int> adj[N];
 int dp[N];
 int dfs(int u, int p) {
        int mx1 = 0, mx2 = 0, res = 0, cnt = 0;
        for(int v: adj[u]) if(v != p) {
                res = max(res, dfs(v, u));
                if(dp[v] > mx1) {
                        mx2 = mx1;
                        mx1 = dp[v];
                } else if(dp[v] > mx2) mx2 = dp[v];
        }
        dp[u] = 1 + mx1;
        return max(res, 1 + mx1 + mx2);
 }
 int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n, m; cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         cout << dfs(1, 0) - 1 << endl;
 }
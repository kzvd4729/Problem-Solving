/****************************************************************************************
*  @author: jU_zQxRvd: iShibly, mh755628, kzvd4729           created: Apr/04/2021 15:59                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1510/problem/G
****************************************************************************************/
#include "bits/stdc++.h"
 using namespace std;
using LL = long long;
 constexpr int N = 105;
 vector< int> E[N];
bitset< N> marked, in_chain;
 int depth[N];
int par[N];
int cnt[N];
 void dfs(int u, int h) {
 depth[u] = h;
  for (int v : E[u]) {
  dfs(v, h + 1);
 }
}
 vector< int> ans;
void foobar(int u) {
 ans.push_back(u);
  for (int v : E[u]) {
  if (marked[v]) continue;
  if (in_chain[v]) continue;
  foobar(v);
 }
 for (int v : E[u]) {
  if (marked[v]) continue;
  if (in_chain[v]) {
   foobar(v);
  }
 }
 if (u != 0) ans.push_back(par[u]);
}
 void solve() {
 int n, k;
 cin >> n >> k;
 for (int i = 0; i < n; i++) E[i].clear();
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i < n; i++) {
  cin >> par[i];
  par[i]--;
  E[par[i]].push_back(i);
  cnt[par[i]]++;
 }
  dfs(0, 0);
  marked.reset();
 int total_unmarked = n;
    int last_node = 0;
 for (int i = 1; i < n; i++) {
  if (depth[i] < k && depth[i] > depth[last_node]) {
   last_node = i;
  }
 }
  in_chain.reset();
 int z = last_node;
 while (z != 0) {
  in_chain[z] = 1;
  z = par[z];
 }
 in_chain[0] = 1;
 assert(z == 0);
  for (int i = n - 1; i > 0; i--) {
  if (total_unmarked <= k) break;
  if (in_chain[i]) continue;
   if (cnt[i] == 0) {
   total_unmarked--;
   marked[i] = 1;
   cnt[par[i]]--;
  }
 }
  assert(total_unmarked == k);
  ans.clear();
 foobar(0);
 while (ans.back() != last_node) ans.pop_back();
  cout << ans.size() - 1 << "\n";
 for (int x : ans) cout << x + 1 << ' ';
  cout << "\n";
}
 int main() {
 cin.tie(nullptr)->sync_with_stdio(false); 
  int t;
 cin >> t;
  while (t--) solve();
}
 
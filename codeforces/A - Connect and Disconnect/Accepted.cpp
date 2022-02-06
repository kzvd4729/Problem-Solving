/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2019 20:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 16200 KB                             
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
typedef pair<int, int> ii; 
 const int N = 3e5 + 10; 
 int p[N], sz[N], ans; 
stack<int> st; 
 int n, k, u[N << 1], v[N << 1], o[N << 1];
char op[N << 1]; 
map<ii, int> mp; 
 int find(int u) {
    while(p[u] != u) u = p[u]; // Notice: No path compression. Path Compression will make the algorithm O(n^2) 
    return u; 
}
void Union(int u, int v) {
    u = find(u); v = find(v); 
    if(u == v) return; 
    if(sz[u] > sz[v]) swap(u, v); // Attach small tree to larger, to keep height O(log n)
    p[u] = v; 
    sz[v] += sz[u];
    ans--; 
    st.push(u); // this means u was attached to p[u] 
}
void rollbax(int t) { // Rollback updates until stack size is t. 
    while(st.size() > t) {
        int u = st.top(); st.pop(); 
        sz[p[u]] -= sz[u]; 
        p[u] = u; ans++;
    }
}
void solve(int l, int r) {
    // Possible optimization: If no queries in range -> return; 
    if(l == r) {
        if(op[l] == '?') 
            printf("%d\n", ans);
        return; 
    } 
    int m = l + r >> 1, now = st.size(); // Backup the size of stack 'now' 
        // For remove queries in [m+1,r], if it was added before l, then union it to dsu. 
    for(int i = m + 1; i <= r; i++) 
        if(o[i] < l) Union(u[i], v[i]); 
    solve(l, m); // Go solve left side. 
    rollbax(now); // Remove previously added edges.  
        // For add queries in [l, m], it it won't be removes in [m+1,r], then add it to dsu. 
    for(int i = l; i <= m; i++) 
        if(o[i] > r) Union(u[i], v[i]);
    solve(m + 1, r); // Solve right side. 
    rollbax(now); // Rollback
}
 int main(int argc, char const *argv[]) {
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
        scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) 
        p[i] = i, sz[i] = 1; 
     if(!k) return 0;
     for(int i = 1; i <= k; i++) {
        scanf(" %c", &op[i]);
        if(op[i] == '?') continue; 
         scanf("%d %d", &u[i], &v[i]);
        if(u[i] > v[i]) 
            swap(u[i], v[i]); 
         ii x(u[i], v[i]); 
        if(mp.count(x)) {
            o[i] = mp[x]; // o[i] = other end of i-th query; for remove query when it was added and vice versa. 
            o[o[i]] = i; 
            mp.erase(x); 
        } else {
            mp[x] = i; 
        }
    }
    int idx = k; 
    for(auto it : mp) { // For convenience, remove existing add queries. 
        o[it.second] = ++idx; 
        o[idx] = it.second; 
        op[idx] = '-';
        tie(u[idx], v[idx]) = it.first; 
    }
    ans = n; // Initially n components
    solve(1, idx); 
}
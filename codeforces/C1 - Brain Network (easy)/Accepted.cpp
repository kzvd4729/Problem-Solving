/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 14:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/690/problem/C1
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 const int N = 1001;
 int p[N];
 int find_parent(int x) {
        return p[x] = (p[x] != x) ? find_parent(p[x]) : p[x];
}
 int main() {
        for(int i = 1; i < N; i++) p[i] = i;
        int n, m; cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            int a = find_parent(u);
            int b = find_parent(v);
            if(a == b) {
                cout << "no" << endl;
                return 0;
            } else p[a] = b;
        }
        for(int i = 1; i <= n; i++) if(find_parent(1) != find_parent(i)) {
            cout << "no" << endl;
            return 0;
        }
        cout << "yes" << endl;
}
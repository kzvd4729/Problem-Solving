/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2019 20:30                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 300003
using namespace std;
int n, q;
vector <int> queries;
vector <pair <int, int> > tr[MAXN << 2];
void update(int v, int l, int r, int ll, int rr, int a, int b)
{
    if (l > rr || r < ll)
        return;
    if (l >= ll && r <= rr)
    {
        tr[v].push_back({a, b});
        return;
    }
    int mid = (l + r) >> 1;
    update(v << 1, l, mid, ll, rr, a, b);
    update((v << 1) + 1, mid + 1, r, ll, rr, a, b);
}
map <pair <int, int>, int> in;
void read()
{
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        string type;
        cin >> type;
        if (type == '?')
            queries.push_back(i);
        else
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            if (type == '+')
                in[{a, b}] = i;
            else
            {
                update(1, 1, q, in[{a, b}], i, a, b);
                in.erase({a, b});
            }
        }
    }
    for (auto i: in)
        update(1, 1, q, i.second, q, i.first.first, i.first.second);
}
int par[MAXN], sz[MAXN];
stack <int> st;
int find(int ver)
{
    while (ver != par[ver])
        ver = par[ver];
    return ver;
}
void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
    st.push(a);
}
void rollback(int moment)
{
    while (st.size() > moment)
    {
        int curr = st.top();
        st.pop();
        sz[par[curr]] -= sz[curr];
        par[curr] = curr;
    }
}
int ans[MAXN];
void dfs(int v, int l, int r)
{
    if (l > r)
        return;
    int moment = st.size();
    for (auto i: tr[v])
        merge(i.first, i.second);
    if (l == r)
        ans[l] = cnt;
    else
    {
        int mid = (l + r) >> 1;
        dfs(v << 1, l, mid);
        dfs((v << 1) + 1, mid + 1, r);
    }
    rollback(moment);
}
void solve()
{
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
    dfs(1, 1, q);
    for (auto i: queries)
        cout << ans[i] << endl;
}
int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read();
    solve();
}
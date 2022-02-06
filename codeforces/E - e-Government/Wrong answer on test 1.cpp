/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 14:10                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 144800 KB                            
*  problem: https://codeforces.com/contest/163/problem/E
****************************************************************************************/
#include <bits/stdc++.h>
 using namespace std;
 const int maxn = 1e6 + 42, sigma = 26;
int to[maxn][sigma];
int link[maxn], cnt[maxn];
vector<int> g[maxn];
int sz = 1;
 int add_str(string s)
{
    int v = 0;
    for(auto c: s)
    {
        c -= 'a';
        if(!to[v][c])
            to[v][c] = sz++;
        v = to[v][c];
    }
    cnt[v] = 1;
    return v;
}
 void push_links()
{
    int q[maxn];
    int st = 0, fi = 1;
    q[0] = 0;
    while(st < fi)
    {
        int v = q[st++];
        int u = link[v];
        for(int c = 0; c < sigma; c++)
        {
            if(v==0)
            {
              link[to[v][c]] = 0;
            }
            else if(to[v][c])
            {
                link[to[v][c]] = to[u][c];
                q[fi++] = to[v][c];
            }
            else
            {
                to[v][c] = to[u][c];
            }
        }
    }
}
 int add[4 * maxn];
 void upd(int a, int b, int c, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
    {
        add[v] += c;
        return;
    }
    if(r <= a || b <= l)
        return;
    int m = (l + r) / 2;
    upd(a, b, c, 2 * v, l, m);
    upd(a, b, c, 2 * v + 1, m, r);
}
 int get(int pos, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
        return add[v];
    int m = (l + r) / 2;
    if(pos < m)
        return add[v] + get(pos, 2 * v, l, m);
    else
        return add[v] + get(pos, 2 * v + 1, m, r);
}
 int in[maxn], out[maxn];
int t;
 void dfs(int v = 0)
{
    in[v] = t++;
    for(auto u: g[v])
        dfs(u);
    out[v] = t;
    upd(in[v], out[v], cnt[v]);
}
 int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int v[k + 1];
    for(int i = 1; i <= k; i++)
    {
        string s;
        cin >> s;
        v[i] = add_str(s);
    }
    push_links();
    for(int i = 1; i < sz; i++)
        g[link[i]].push_back(i);
    dfs();
    while(n--)
    {
        string t;
        cin >> t;
        if(t[0] == '?')
        {
            int v = 0;
            int ans = 0;
            for(int i = 1; i < t.size(); i++)
            {
                v = to[v][t[i] - 'a'];
                ans += get(in[v]);
            }
            cout << ans << "\n";
        }
        else
        {
            int num = atoi(t.c_str());
            int t = abs(num) / num;
            num = abs(num);
            if(cnt[v[num]] == (t + 1) / 2)
                continue;
            cnt[v[num]] += t;
            upd(in[v[num]], out[v[num]], t);
        }
    }
}
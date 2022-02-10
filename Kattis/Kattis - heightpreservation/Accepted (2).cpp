/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 20:04:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1710                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-heightpreservation
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define MX 1000000
#define ff first
#define ss second


vector<int>g[MX+5], mp[MX+5], G[MX+5];

unordered_map<int, int>M;

int T[2][4*MX], row[MX+5], col[MX+5], X[MX+5], Y[MX+5];
int vis[MX+5], vis1[MX+5], vis2[MX+5];

void up(int cr, int p, int l, int h, int x, int vl)
{
    if(l==h)
    {
        T[cr][p]=vl; return;
    }
    int m=(l+h)/2;
    if(x<=m) up(cr, 2*p, l, m, x, vl);
    else     up(cr, 2*p+1, m+1, h, x, vl);
    T[cr][p]=max(T[cr][2*p], T[cr][2*p+1]);
}

int Q(int cr, int p, int l, int h, int x, int y)
{
    if(l>y||h<x) return 0;
    if(l>=x && h<=y) return T[cr][p];
    int m=(l+h)/2;
    return max(Q(cr, 2*p, l, m, x, y), Q(cr, 2*p+1, m+1, h, x, y));
}

int n, m, k=0;

int dfs(int x, int p)
{
    int r=X[x], c=Y[x]; vis1[x]=1;
    int mx=Q(0, 1, 1, n*m, r*m+1, r*m+m);
    mx=max(mx, Q(1, 1, 1, n*m, c*n+1, c*n+n));

    for(auto u:G[x])
    {
        if(u==p||vis1[u]) continue;
        mx=max(mx, dfs(u, x));
    }
    return mx;
}

void dfs2(int x, int p, int mx)
{
    int r=X[x], c=Y[x]; vis2[x]=1;
    up(0, 1, 1, n*m, r*m+c+1, mx);
    up(1, 1, 1, n*m, c*n+r+1, mx);
    for(auto u:G[x])
    {
        if(u==p||vis2[u]) continue;
        dfs2(u, x, mx);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //////////////////////////////////////////////////


    cin>>n>>m;
    priority_queue<pair<int, pair<int, int> > >pq;
    for(int i=0; i<n; i++)
    {
        g[i].resize(m); mp[i].resize(m);
        for(int j=0; j<m; j++)
        {
            cin>>g[i][j]; pq.push({-g[i][j], {i, j}});
            mp[i][j]=++k; X[k]=i, Y[k]=j;
        }
    }

    for(int i=0; i<n; i++)
    {
        M.clear();
        for(int j=0; j<m; j++)
        {
            int x=g[i][j], vl=M[x];
            if(vl)
            {
                int id=mp[i][j], id1=mp[i][vl-1];
                G[id].push_back(id1); G[id1].push_back(id);
            }
            M[x]=j+1;
        }
    }

    for(int j=0; j<m; j++)
    {
        M.clear();
        for(int i=0; i<n; i++)
        {
            int x=g[i][j], vl=M[x];
            if(vl)
            {
                int id=mp[i][j], id1=mp[vl-1][j];
                G[id].push_back(id1); G[id1].push_back(id);
            }
            M[x]=i+1;
        }
    }

    int rs=0;
    while(!pq.empty())
    {
        pair<int, pair<int, int> >ret=pq.top();
        pq.pop();
        int x=-ret.ff; int r=ret.ss.ff, c=ret.ss.ss;
        int id=mp[r][c];
        if(vis2[id]) continue;

        int mx=dfs(id, 0);
        dfs2(id, 0, mx+1);
        rs=max(rs, mx+1);
    }
    cout<<rs<<endl;
    return 0;
}
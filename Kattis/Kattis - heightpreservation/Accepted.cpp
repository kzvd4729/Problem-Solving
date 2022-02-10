/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 21:38:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 950                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-heightpreservation
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define MX 1000000
#define ff first
#define ss second


vector<int>g[MX+5], mp[MX+5], G[MX+5];

unordered_map<int, int>M;

int row[MX+5], col[MX+5], X[MX+5], Y[MX+5], vis1[MX+5], vis2[MX+5];


int n, m, k=0;

int dfs(int x, int p)
{
    int r=X[x], c=Y[x]; vis1[x]=1;
    int mx=max(row[r],col[c]);
    for(auto u:G[x])
    {
        if(u==p||vis1[u]) continue;
        mx=max(mx, dfs(u, x));
    }
    return mx;
}

void dfs2(int x, int p, int mx)
{
    int r=X[x], c=Y[x]; vis2[x]=1; g[r][c]=mx;
    row[r]=max(mx, row[r]); col[c]=max(col[c], mx);
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
    vector<pair<int, int> >v;
    for(int i=0; i<n; i++)
    {
        g[i].resize(m); mp[i].resize(m);
        for(int j=0; j<m; j++)
        {
            cin>>g[i][j];
            mp[i][j]=++k; X[k]=i, Y[k]=j;
            v.push_back({g[i][j], k});
        }
    }
    sort(v.begin(), v.end());

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
    for(int i=0; i<v.size(); i++)
    {
         pair<int, int>ret=v[i];
        int x=-ret.ff; int r=X[ret.ss], c=Y[ret.ss];
        int id=mp[r][c];
        if(vis2[id]) continue;

        int mx=dfs(id, 0);
        dfs2(id, 0, mx+1);
        rs=max(rs, mx+1);
    }
    cout<<rs<<endl;
    return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 19:09:10                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-heightpreservation
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define MX 1000000
#define ff first
#define ss second

vector<int>g[MX+5];

int T[2][4*MX], row[MX+5], col[MX+5];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //////////////////////////////////////////////////

    int n, m;
    cin>>n>>m;
    priority_queue<pair<int, pair<int, int> > >pq;
    for(int i=0; i<n; i++)
    {
        g[i].resize(m);
        for(int j=0; j<m; j++)
        {
            cin>>g[i][j]; pq.push({-g[i][j], {i, j}});
        }
    }

    int rs=0;
    while(!pq.empty())
    {
        pair<int, pair<int, int> >ret=pq.top();
        pq.pop();
        int x=-ret.ff; int r=ret.ss.ff, c=ret.ss.ss;
        int mx=Q(0, 1, 1, n*m, r*m+1, r*m+m);
        mx=max(mx, Q(1, 1, 1, n*m, c*n+1, c*n+n));
        if(row[r]==x || col[c]==x)
        {
            up(0, 1, 1, n*m, r*m+c+1, mx);
            up(1, 1, 1, n*m, c*n+r+1, mx);
        }
        else
        {
            rs=max(rs, mx+1);
            up(0, 1, 1, n*m, r*m+c+1, mx+1);
            up(1, 1, 1, n*m, c*n+r+1, mx+1);
        }
        row[r]=col[c]=x;
    }
    cout<<rs<<endl;
    return 0;
}
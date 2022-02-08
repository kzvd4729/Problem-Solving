/****************************************************************************************
*  @author: kzvd4729                                         created: 05-02-2018 15:32:09                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.15 sec                                        memory_used: 16.2M                                
*  problem: https://www.codechef.com/FEB18/problems/POINPOLY
****************************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define SIZE(x) ((LL)(x).size())
#define Det(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))
using namespace std;
typedef long long LL;
struct point
{
    LL x,y;
    point(LL x = 0, LL y = 0) : x(x), y(y) {}
    bool operator ==(point& a)
    {
        return a.x==x && a.y==y;
    }
};
vector<point>vec;
bool check(point p)
{
    LL a = 1, b = SIZE(vec)-1, c;
    if (Det(vec[0], vec[a], vec[b]) > 0) swap(a,b);
    if (Det(vec[0], vec[a], p) >= 0 || Det(vec[0], vec[b], p) <= 0) return false
        ;
    while(abs(a-b) > 1)
    {
        c = (a+b)/2;
        if (Det(vec[0], vec[c], p) > 0) b = c;
        else a = c;
    }
    return Det(vec[a], vec[b], p) < 0;
}
LL dr[]= {0,0,1,-1};
LL dc[]= {1,-1,0,0};
map<pair<LL,LL>,LL>mp;
LL lim,n,t;
void dfs(point pp)
{
    if(mp.size()>=lim)return ;
    if(!check(pp)||mp[ {pp.x,pp.y}])return ;
    mp[ {pp.x,pp.y}]=1;
    dfs({pp.x+dr[0],pp.y+dc[0]});
    dfs({pp.x+dr[1],pp.y+dc[1]});
    dfs({pp.x+dr[2],pp.y+dc[2]});
    dfs({pp.x+dr[3],pp.y+dc[3]});
}
void extra(void)
{
    for(auto xx:vec)
    {
        dfs({xx.x+dr[0],xx.y+dc[0]});
        dfs({xx.x+dr[1],xx.y+dc[1]});
        dfs({xx.x+dr[2],xx.y+dc[2]});
        dfs({xx.x+dr[3],xx.y+dc[3]});
    }
    if(mp.size()<lim)cout<<-1<<endl;
    else
    {
        for(map<pair<LL,LL>,LL>::iterator it=mp.begin(); it!=mp.end(); it++)
        {
            if(lim==0)break;
            cout<<it->first.first<<" "<<it->first.second<<endl;
            lim--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        vec.clear();
        mp.clear();
        point p;
        LL n;
        cin >> n;
        lim=n/10;
        for(LL i=0; i<n; i++)
        {
            cin>>p.x>>p.y;
            vec.push_back(p);
        }
        extra();
    }
//    LL m;
//    cin >> m;
//    bool ok = 1;
//    for(LL i=0;i<m;i++)
//    {
//        cin >> p.x >> p.y;
//        if (!check(p)) ok = 0;
//    }
//    cout << (ok ? "YES" : "NO");
    return 0;
}
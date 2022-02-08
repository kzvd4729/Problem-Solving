/****************************************************************************************
*  @author: kzvd4729                                         created: 05-02-2018 14:44:27                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/FEB18/problems/POINPOLY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,lim;
long dr[]= {0,0,1,-1};
long dc[]= {1,-1,0,0};
struct point
{
    long x,y;
} p[100005];
map<pair<long,long>,long>mp;
bool cmp(point A,point B)
{
    if(A.x!=B.x)return A.x<B.x;
    else return A.y<B.y;
}
long det(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool check(point pp)
{
    long a = 2, b = n, c;
    if (det(p[1], p[a], p[b]) > 0) swap(a,b);
    if (det(p[1], p[a], pp) >= 0 || det(p[1], p[b], pp) <= 0) return false;
    while(abs(a-b) > 1)
    {
        c = (a+b)/2;
        if (det(p[1], p[c], pp) > 0) b = c;
        else a = c;
    }
    return det(p[a], p[b], pp) < 0;
}
void dfs(long x,long y)
{
    if(mp.size()>=lim)return ;
    if(mp[ {x,y}]||!check({x,y}))return ;
    mp[ {x,y}]=1;
    dfs(x+dr[0],y+dc[0]);
    dfs(x+dr[1],y+dc[1]);
    dfs(x+dr[2],y+dc[2]);
    dfs(x+dr[3],y+dc[3]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        lim=n/10;
        for(int i=1; i<=n; i++)cin>>p[i].x>>p[i].y;
        ///sort(p+1,p+n+1,cmp);
        for(int i=1; i<=n; i++)
        {
            dfs(p[i].x+dr[0],p[i].y+dc[0]);
            dfs(p[i].x+dr[1],p[i].y+dc[1]);
            dfs(p[i].x+dr[2],p[i].y+dc[2]);
            dfs(p[i].x+dr[3],p[i].y+dc[3]);
        }
        if(mp.size()<lim)cout<<-1<<endl;
        else
        {
            for(map<pair<long,long>,long>::iterator it=mp.begin();it!=mp.end
                ();it++)
            {
                if(lim==0)break;
                cout<<it->first.first<<" "<<it->first.second;
                lim--;
            }
        }
    }
    return 0;
}
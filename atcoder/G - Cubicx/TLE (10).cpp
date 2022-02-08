/****************************************************************************************
*  @author: kzvd4729                                         created: 2022-02-06 01:09:09                      
*  solution_verdict: TLE                                     language: C++ (GCC 9.2.1)                         
*  run_time: 3310 ms                                         memory_used: 104992 KB                            
*  problem: https://atcoder.jp/contests/abc238/tasks/abc238_g
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 using namespace std;
using namespace __gnu_pbds;
 template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
 #define PI acos(-1)
#define ll long long
 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
 const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 bool mark[N];
vector<pair<int,int>>primeDivs[N];
 void PreCal()
{
    int i,j,k;
    for(i=2;i<=N/2;i+=2)
    {
        j=i;
        primeDivs[i].emplace_back(2,0);
        while(j%2 == 0)j/=2, primeDivs[i].back().second=(primeDivs[i].back().second+1)%3;
    }
    for(i=3;i<=N/2;i+=2)
    {
        if(mark[i])continue;
        for(j=i;j<=N/2;j+=i)
        {
            k=j, mark[j]=1;
            primeDivs[j].emplace_back(i,0);
            while(k%i == 0)k/=i, primeDivs[j].back().second=(primeDivs[j].back().second+1)%3;
        }
    }
}
  ///Calculation
struct query
{
    int l,r,id;
}q[M];
bool ans[M];
int l,r,k,ok,a[M],cnt[N];
 bool Compare(query &x,query &y)
{
    int a=x.l/k,b=y.l/k;
    if(a == b)return x.r < y.r;
    return a < b;
}
 void Add(int x)
{
    x=a[x];
    if(x == 1)return;
    for(auto [i,j] : primeDivs[x])
    {
        if(cnt[i])--ok;
        cnt[i] += j;
        if(cnt[i]>=3)cnt[i]-=3;
        if(cnt[i])++ok;
    }
}
 void Reduce(int x)
{
    x=a[x];
    if(x == 1)return;
    for(auto [i,j] : primeDivs[x])
    {
        if(cnt[i])--ok;
        cnt[i] -= j;
        if(cnt[i]<0)cnt[i]+=3;
        if(cnt[i])++ok;
    }
}
///Calculation
   int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x;
     PreCal();
     cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    k=sqrt(m);
    for(i=0;i<m;i++)
    {
        cin >> x;
        q[i].l=x-1;
        cin >> x;
        q[i].r=x-1;
        q[i].id=i;
    }
    sort(q,q+m,Compare);
    l=0,r=-1;
    for(i=0;i<m;i++)
    {
        while(l > q[i].l)Add(--l);
        while(r < q[i].r)Add(++r);
        while(l < q[i].l)Reduce(l++);
        while(r > q[i].r)Reduce(r--);
        ans[q[i].id]=(ok == 0);
    }
    for(i=0;i<m;i++)
    {
        if(ans[i])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: 2022-02-06 16:22:29                      
*  solution_verdict: TLE                                     language: C++ (GCC 9.2.1)                         
*  run_time: 3311 ms                                         memory_used: 104204 KB                            
*  problem: https://atcoder.jp/contests/abc238/tasks/abc238_g
****************************************************************************************/
#pragma GCC optimize("Ofast")
 #include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 using namespace std;
using namespace __gnu_pbds;
 #define ll long long
 template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
 //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
 const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 bool multiple[N];
int divCnt[N][10],lp[1005];
vector<int>primes,primeDivs[N];
 void PreCal()
{
    int i,j,l=0;
    for(i=2; i<=1000; i++)
    {
        if(!lp[i])lp[i]=i, primes.emplace_back(i), ++l;
        for(j=0; j<l && primes[j]<=lp[i] && i*primes[j]<=1000; j++)lp[i*primes[j]]=primes[j];
    }
    for(i=0; i<N; i+=3)multiple[i]=1;
}
 struct query
{
    int l,r,id;
} q[M];
bool ans[M];
int k=450,a[M],cnt[N];
 bool Compare(query &x,query &y)
{
    int a=x.l/k,b=y.l/k;
    if(a == b)
    {
      if(a%2)return x.r > y.r;
      else return x.r < y.r;
    }
    return a < b;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l=0,ln,m,n,ok=0,r=-1,x,y;
     PreCal();
     cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> a[i], x=a[i];
        if(!primeDivs[x].empty())continue;
        for(int it : primes)
        {
            if(it*it > x)break;
            if(x%it == 0)
            {
                ln=(int)primeDivs[a[i]].size();
                primeDivs[a[i]].emplace_back(it);
                while(x%it == 0)x/=it, divCnt[a[i]][ln]++;
            }
        }
        if(x > 1)
        {
            ln=(int)primeDivs[a[i]].size();
            primeDivs[a[i]].emplace_back(x), divCnt[a[i]][ln]++;
        }
    }
    for(i=0; i<m; i++)
    {
        cin >> x;
        q[i].l=x-1;
        cin >> x;
        q[i].r=x-1;
        q[i].id=i;
    }
    sort(q,q+m,Compare);
    for(i=0; i<m; i++)
    {
        while(l > q[i].l)
        {
            x=a[--l];
            ln=(int)primeDivs[x].size();
            for(j=0; j<ln; j++)
            {
                y=primeDivs[x][j];
                if(!multiple[cnt[y]])--ok;
                cnt[y] += divCnt[x][j];
                if(!multiple[cnt[y]])++ok;
            }
        }
        while(r < q[i].r)
        {
            x=a[++r];
            ln=(int)primeDivs[x].size();
            for(j=0; j<ln; j++)
            {
                y=primeDivs[x][j];
                if(!multiple[cnt[y]])--ok;
                cnt[y] += divCnt[x][j];
                if(!multiple[cnt[y]])++ok;
            }
        }
        while(l < q[i].l)
        {
            x=a[l++];
            ln=(int)primeDivs[x].size();
            for(j=0; j<ln; j++)
            {
                y=primeDivs[x][j];
                if(!multiple[cnt[y]])--ok;
                cnt[y] -= divCnt[x][j];
                if(!multiple[cnt[y]])++ok;
            }
        }
        while(r > q[i].r)
        {
            x=a[r--];
            ln=(int)primeDivs[x].size();
            for(j=0; j<ln; j++)
            {
                y=primeDivs[x][j];
                if(!multiple[cnt[y]])--ok;
                cnt[y] -= divCnt[x][j];
                if(!multiple[cnt[y]])++ok;
            }
        }
        ans[q[i].id]=(ok == 0);
    }
    for(i=0; i<m; i++)
    {
        if(ans[i])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
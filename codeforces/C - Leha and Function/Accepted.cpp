/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 920 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/841/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
struct data
{
    long id;
    long vl;
}a[200005];
bool cmp(data A,data B)
{
    return A.vl<B.vl;
}
long b[200005],d[200005],n,ans[200005],id;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    id=0;
    for(int i=n;i>=1;i--)
    {
        d[++id]=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].vl;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        ans[a[i].id]=d[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
      return 0;
}
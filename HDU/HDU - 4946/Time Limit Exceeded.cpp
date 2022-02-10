/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 23:46:14                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-4946
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,x=1e4;

int a[N+2],b[N+2],c[N+2],cnt[N+2];
int ck(int n,int x,int y)
{
  int mn=inf+inf,id;
  for(int i=1;i<=n;i++)
  {
    if(cnt[i]==0)continue;
    int d=(x-a[i])*(x-a[i])+(y-b[i])*(y-b[i]);
    if(d<mn)mn=d,id=i;
  }
  return id;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n,tc=0;
  while(cin>>n)
  {
    if(n==0)break;

    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(mx,c[i]);

    for(int i=1;i<=n;i++)
    {
      if(c[i]==mx)cnt[i]=1;
      else cnt[i]=0;
    }

    //for(int i=1;i<=n;i++)cout<<cnt[i];cout<<endl;

    for(int i=-x;i<=x;i++)
    {
      cnt[ck(n,i,x)]++;
      cnt[ck(n,i,-x)]++;
      cnt[ck(n,x,i)]++;
      cnt[ck(n,-x,i)]++;
    }
    cout<<"Case #"<<++tc<<": ";
    for(int i=1;i<=n;i++)
    {
      if(cnt[i]>1)cout<<1;
      else cout<<0;
    }
    cout<<'\n';
  }
  return 0;
}
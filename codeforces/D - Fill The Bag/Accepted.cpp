/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 16:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1303/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],cnt[30+2];
bool make(long x)
{
  vector<int>v;
  for(int i=29;i>=0;i--)
  {
    for(int j=1;j<=cnt[i];j++)
    {
      if(x>=(1<<i))
      {
        x-=(1<<i);v.push_back(i);
      }
    }
  }
  if(x)return false;
  for(auto x:v)cnt[x]--;return true;
}
void add(int x,int f)
{
  for(int j=0;j<30;j++)
    if(x&(1<<j))cnt[j]+=f;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(cnt,0,sizeof(cnt));
    long x,n;cin>>x>>n;int ans=0,ff=0;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
     for(int i=1;i<=n;i++)add(aa[i],1);
    /*for(int i=0;i<30;i++)
      cout<<cnt[i]<<" ";
    cout<<endl;*/
    for(long i=0;i<60;i++)
    {
      if(!(x&(1LL<<i)))continue;
      long y=(1LL<<i);//cout<<y<<endl;
      if(make(y))continue;
       int f=0;
      for(int j=i;j<30;j++)
      {
        if(!cnt[j])continue;
        f=1;ans+=(j-i);cnt[j]--;
        for(int k=i;k<j;k++)
          cnt[k]++;
        break;
      }
      if(f==0)ff=1;
    }
    if(ff)cout<<-1<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}
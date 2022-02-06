/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 18:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 11100 KB                             
*  problem: https://codeforces.com/gym/102307/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n,fr[100+2];
bool dp[N+2];
void path(int x)
{
  memset(fr,0,sizeof(fr));
  while(x)
  {
    for(int i=n;i>=1;i--)
    {
      if(x-aa[i]<0)continue;
      if(dp[x-aa[i]])
      {
        fr[i]++;x-=aa[i];
        break;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  //sort(aa+1,aa+n+1);
  dp[0]=1;
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i-aa[j]<0)continue;
      dp[i]|=dp[i-aa[j]];
      if(dp[i])break;
    }
  }
  vector<int>v;
  for(int i=1;i<=N;i++)
    if(dp[i])v.push_back(i);
  int gmx=0,rmn=1e6;rmn++;
  int lo=0,hi=v.size()-1,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;cout<<1<<endl;
    path(v[md]);int f=0;
    for(int i=1;i<=n;i++)
    {
      if(f)cout<<" ";f=1;
      cout<<fr[i];
    }
    cout<<endl;
    string s;cin>>s;
    if(s=="green")
    {
      lo=md;gmx=max(gmx,v[md]);
    }
    else if(s=="yellow")
    {
      cout<<2<<endl;
      cout<<v[md]<<endl;
      exit(0);
    }
    else
    {
      hi=md;
      rmn=min(rmn,v[md]);
    }
  }
  for(md=lo;md<=hi;md++)
  {
    cout<<1<<endl;
    path(v[md]);int f=0;
    for(int i=1;i<=n;i++)
    {
      if(f)cout<<" ";f=1;
      cout<<fr[i];
    }
    cout<<endl;
    string s;cin>>s;
    if(s=="yellow")
    {
      cout<<2<<endl;
      cout<<v[md]<<endl;
      exit(0);
    }
    else if(s=="green")
    {
      gmx=max(gmx,v[md]);
    }
    else
    {
      rmn=min(rmn,v[md]);
    }
  }
  if(rmn-gmx==2)
  {
    cout<<2<<endl;
    cout<<(gmx+rmn)/2<<endl;
    exit(0);
  }
  cout<<2<<endl;
  cout<<-1<<endl;
  return 0;
}
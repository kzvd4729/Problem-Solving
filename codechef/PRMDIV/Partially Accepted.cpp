/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2018 20:06:22                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 1.46 sec                                        memory_used: 142.6M                               
*  problem: https://www.codechef.com/LTIME62A/problems/PRMDIV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],fr[N+2],t,n,x;
int arr[N+2];
long sum[N+2];
vector<int>dv[N+2];
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;
      sum[j]+=(i*1LL);
    }
  }
  for(int i=2;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      dv[j].push_back(i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  seive();
  cin>>t;
  while(t--)
  {
    cin>>n;
    memset(fr,0,sizeof(fr));
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      fr[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
      int x=arr[i];
      fr[x]--;
      for(auto xx:dv[x])
        if(sum[x]%sum[xx]==0)ans+=(fr[xx]*1LL);
      fr[x]++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
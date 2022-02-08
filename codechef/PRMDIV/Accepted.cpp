/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2018 20:20:20                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.80 sec                                        memory_used: 92.2M                                
*  problem: https://www.codechef.com/LTIME62A/problems/PRMDIV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2],fr[N+2],t,n;
int arr[N+2],x,i,j,l;
long sum[N+2],ans;
vector<int>dv[N+2];
void seive(void)
{
  for(i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(j=i;j<=N;j+=i)
    {
      vis[j]=1;
      sum[j]+=(i*1LL);
    }
  }
  for(i=2;i<=N;i++)
  {
    for(j=i;j<=N;j+=i)
    {
      if(sum[j]%sum[i]==0)
        dv[j].push_back(i);
    }
  }
}
int main()
{
  seive();
  cin>>t;
  while(t--)
  {
    cin>>n;
    ans=0;
    for(i=1;i<=n;i++)
    {
      cin>>arr[i];
      fr[arr[i]]++;
    }
    for(i=1;i<=n;i++)
    {
      x=arr[i];
      fr[x]--;
      for(j=0,l=dv[x].size();j<l;j++)
        ans+=(fr[dv[x][j]]*1LL);
      fr[x]++;
    }
    for(i=1;i<=n;i++)fr[arr[i]]--;
      cout<<ans<<endl;
  }
  return 0;
}
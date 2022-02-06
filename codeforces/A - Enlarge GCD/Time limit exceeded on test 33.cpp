/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2018 21:10                        
*  solution_verdict: Time limit exceeded on test 33          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 80800 KB                             
*  problem: https://codeforces.com/contest/1034/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=15000000;
int arr[300005],ans,cnt[N+2];
bool vis[N+2];
vector<int>pr;
void seive(void)
{
  vis[1]=1;
  pr.push_back(2);
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i])continue;
    pr.push_back(i);
    if(i>10000)continue;
    for(int j=i*i;j<=N;j+=2*i)
      vis[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n,gcd=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    gcd=__gcd(gcd,arr[i]);
  }
  for(int i=1;i<=n;i++)
    arr[i]/=gcd;
  for(int i=1;i<=n;i++)
  {
    int x=arr[i];//if(x==1)continue;
    for(int j=0;pr[j]<=sqrt(x+1);j++)
    {
      if(vis[x]==0)
      {
        if(x>1)
        {
          cnt[x]++;
          ans=max(ans,cnt[x]);
        }
        x=1;
        break;
      }
      if(x%pr[j]==0)
      {
        cnt[pr[j]]++;
        ans=max(ans,cnt[pr[j]]);
        while(x%pr[j]==0)x/=pr[j];
      }
    }
    if(vis[x]==0)
    {
      if(x>1)
      {
        cnt[x]++;
        ans=max(ans,cnt[x]);
      }
    }
  }
  if(ans==0)cout<<-1<<endl;
  else cout<<n-ans<<endl;
  return 0;
}
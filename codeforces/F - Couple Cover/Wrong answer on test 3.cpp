/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2019 18:23                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 58700 KB                             
*  problem: https://codeforces.com/contest/691/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e6;
int aa[N+2],fr[N+2],qm[N+2];
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  int id=0;
  for(int i=1;i<=N;i++)if(fr[i])aa[++id]=i;
  for(int i=N;i>=1;i--)qm[i]=qm[i+1]+fr[i];
  for(int i=1;i<=id;i++)
  {
    for(int j=i+1;j<=id;j++)
    {
      if(aa[i]*aa[j]>N)
      {
        ans[N]+=(1LL*fr[aa[i]]*qm[aa[j]]);
        break;
      }
      ans[aa[i]*aa[j]]+=(1LL*fr[aa[i]]*fr[aa[j]]);
    }
  }
  for(int i=N;i>=1;i--)ans[i]+=ans[i+1];
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;cout<<ans[x]*2LL<<"\n";
  }
  return 0;
}
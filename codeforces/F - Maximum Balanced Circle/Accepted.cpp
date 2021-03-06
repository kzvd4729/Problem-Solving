/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1157/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],fr[N+2],qm[N+2],lk[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i],fr[aa[i]]++;
  for(int i=1;i<=N;i++)
    qm[i]=qm[i-1]+fr[i];
  for(int i=1;i<=N;i++)
  {
    if(fr[i-1]>1)lk[i]=lk[i-1];
    else lk[i]=i-1;
  }
  int mx=0,lt,rt;
  for(int i=1;i<=N;i++)
  {
    int b=lk[i];
    int now=qm[i];if(b)now-=qm[b-1];
    if(now>mx)
    {
      mx=now;lt=b,rt=i;
    }
  }
  cout<<mx<<endl;
  for(int i=lt;i<=rt;i++)
  {
    if(!fr[i])continue;
    cout<<i<<" ";fr[i]--;
  }
  for(int i=rt;i>=lt;i--)
  {
    if(!fr[i])continue;
    while(fr[i]--)
      cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2019 18:41                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 15000 ms                                        memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/690/problem/D3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e6+3;
int len[N+2],dp[100+2][2],ls[2],nw[2];
int big(int b,int p)
{
  int ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int c,w,h;cin>>c>>w>>h;
  for(int i=1;i<=w;i++)len[i]=big(h,i)%mod;
   ls[0]=1;deque<int>dq;dq.push_back(1);
  for(int i=1;i<=c;i++)
  {
    nw[0]=(ls[0]+ls[1])%mod;
    if(dq.size()>h)dq.pop_front();
    int id=0;nw[1]=0;
    for(int j=dq.size()-1;j>=0;j--)
      nw[1]=(1LL*nw[1]+1LL*dq[j]*len[++id])%mod;
    dq.push_back(nw[0]);
    ls[0]=nw[0];ls[1]=nw[1];
  }
  cout<<(ls[0]+ls[1])%mod<<endl;
  return 0;
}
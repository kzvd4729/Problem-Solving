/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 11:16                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/855/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mxp=-2e9,mnp=2e9,mxn=-2e9,mnn=2e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p,q,r;cin>>n>>p>>q>>r;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x<=0)mxp=max(mxp,x),mnp=min(mnp,x);
    else mxn=max(mxn,x),mnn=min(mnn,x);
  }
  //cout<<mxp<<" "<<mnp<<endl;
  auto cal=[](int x)
  {
    long ret=-2e9;
    if(mxp!=-2e9)ret=max(ret,1LL*x*mxp);
    if(mnp!=2e9)ret=max(ret,1LL*x*mnp);
    if(mxn!=-2e9)ret=max(ret,1LL*x*mxn);
    if(mnn!=2e9)ret=max(ret,1LL*x*mnn);
    return ret;
  };
  cout<<cal(p)+cal(q)+cal(r)<<endl;
     return 0;
}
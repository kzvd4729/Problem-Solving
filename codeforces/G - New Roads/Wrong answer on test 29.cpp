/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 19:18                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/746/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],leaf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,t,k;cin>>n>>t>>k;
  for(int i=1;i<=t;i++)cin>>aa[i];
   leaf[t]=aa[t];
  for(int i=t-1;i>=1;i--)
    leaf[i]=leaf[i+1]+max(0,aa[i]-aa[i+1]);
   if(leaf[1]>k)cout<<"-1"<<endl,exit(0);
   int lt=1,rt=1;cout<<n<<endl;
  for(int i=1;i<=t;i++)
  {
    int nlt=rt+1,nrt=rt+aa[i],use=0;
    if(leaf[i]==k)use=min(rt-lt+1,nrt-nlt+1);
    else use=max(1,rt-lt+1-(k-leaf[i]));
     int pt=nlt;
    for(int i=lt;i<lt+use-1;i++)
      cout<<i<<" "<<pt++<<endl;
    for(int i=pt;i<=nrt;i++)
      cout<<lt+use-1<<" "<<i<<endl;
    k-=(rt-lt+1-use);
     lt=nlt,rt=nrt;
  }
  return 0;
}
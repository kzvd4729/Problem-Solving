/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/20/2020 17:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 122 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/238/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,h;cin>>n>>h;
  for(int i=1;i<=n;i++)cin>>aa[i],bb[i]=aa[i];
   sort(aa+1,aa+n+1);
    if(n==2)cout<<0<<endl<<1<<" "<<1<<endl,exit(0);
   if(aa[n]+aa[n-1]-aa[1]-aa[2]<=max(aa[n]+aa[n-1],aa[n]+aa[1]+h)-min(aa[1]+aa[2]+h,aa[2]+aa[3]))
  {
    cout<<aa[n]+aa[n-1]-aa[1]-aa[2]<<endl;
    for(int i=1;i<=n;i++)cout<<1<<" ";cout<<endl;
  }
  else
  {
    cout<<max(aa[n]+aa[n-1],aa[n]+aa[1]+h)-min(aa[1]+aa[2]+h,aa[2]+aa[3])<<endl;
    for(int i=1;i<=n;i++)
    {
      if(bb[i]==aa[1]){cout<<1<<" ";aa[1]=-1;}
      else cout<<2<<" ";
    }
    cout<<endl;
  }
   return 0;
}
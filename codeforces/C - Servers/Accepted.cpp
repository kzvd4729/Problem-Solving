/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 18:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/747/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int oc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
   while(q--)
  {
    int t,k,d;cin>>t>>k>>d;
     int cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(oc[i]<t)cnt++;
    }
    if(cnt<k){cout<<-1<<"\n";continue;}
    int sm=0;
    for(int i=1;i<=n;i++)
    {
      if(!k)break;
      if(oc[i]<t)k--,oc[i]=t+d-1,sm+=i;
    }
    cout<<sm<<"\n";
  }
  return 0;
}
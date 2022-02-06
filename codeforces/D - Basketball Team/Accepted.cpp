/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 23:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/108/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int mm[N+2],n,m,h,tt;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m>>h;
  for(int i=1;i<=m;i++)
    cin>>mm[i];
  n--,mm[h]--;
  for(int i=1;i<=m;i++)
    tt+=mm[i];
  if(tt<n)cout<<-1<<endl,exit(0);
  if(mm[h]==0)cout<<0<<endl,exit(0);
  int rm=tt-mm[h];
  if(rm<n)cout<<1<<endl,exit(0);
   vector<int>up,dw;
   for(int i=n;i>=1;i--)
    dw.push_back(i);
  for(int i=rm-n;i>=1;i--)
    dw.push_back(i);
  for(int i=rm;i>=1;i--)
    up.push_back(i);
   for(int i=n;i>=1;i--)
    up.push_back(i);
  for(int i=tt-n;i>=1;i--)
    up.push_back(i);
  for(int i=tt;i>=1;i--)
    dw.push_back(i);
  sort(up.begin(),up.end());
  sort(dw.begin(),dw.end());
   double ans=1.0;
  for(int i=0;i<max((int)up.size(),(int)dw.size());i++)
  {
    if(i<up.size())ans*=up[i];
    if(i<dw.size())ans*=(1.0/(dw[i]*1.0));
  }
//  for(int i=0;i<up.size();i++)
//  {
//    for(int j=0;j<dw.size();j++)
//    {
//      if(dw[j]%up[i]==0)up[i]/=up[i],dw[j]/=up[i];
//      if(up[i]%dw[j]==0)dw[j]/=dw[j],up[i]/=dw[j];
//    }
//  }
   cout<<setprecision(10)<<fixed<<1.0-ans<<endl;
  return 0;
}
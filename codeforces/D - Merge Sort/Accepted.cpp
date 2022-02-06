/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2019 15:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/873/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],k;
void merg(int lo,int hi,int lt,int rt)
{
  //cout<<lo<<" "<<hi<<" "<<lt<<" "<<rt<<" "<<k<<endl;
  if(k==0||lo+1==hi)
  {
    for(int i=lo;i<hi;i++)aa[i]=lt+i-lo;
    return ;
  }
  int md=(lo+hi)/2;
  if(md>lo)k--;if(hi>md)k--;
  if(md>lo)
    merg(lo,md,rt-(md-lo)+1,rt);
  if(hi>md)
    merg(md,hi,lt,lt+(hi-md)-1);
}
int cnt;vector<int>v;
void _merg(int lo,int hi)
{
  int f=0;cnt++;
  for(int i=lo+1;i<hi;i++)
  {
    if(v[i]<v[i-1])f=1;
  }
  if(!f)return ;
  int md=(lo+hi)/2;
  _merg(lo,md);_merg(md,hi);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;int kk=k;if(k%2==0||k>n+n)cout<<-1<<endl,exit(0);
  k--;merg(0,n,1,n);//cout<<k<<endl;
  for(int i=0;i<n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
   for(int i=0;i<n;i++)
    v.push_back(aa[i]);
    _merg(0,n);//if(kk!=cnt)assert(0);
   return 0;
}
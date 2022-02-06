/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 21:20                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1486/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int ask(int l,int r)
{
  if(l==r)return -1;
  cout<<"? "<<l<<" "<<r<<endl;
  int x;cin>>x;
  return x;
}
int ck(int lo,int hi,int id)
{
  int md=(lo+hi)/2;
  if(id<=md)
  {
    int x=ask(min(id,lo),md);
    if(x==id)return 1;
    else return 2;
  }
  else
  {
    int x=ask(md+1,max(hi,id));
    if(x==id)return 2;
    else return 1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   int smx=ask(1,n);
   int lo=1,hi=n,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    if(ck(lo,hi,smx)==1)hi=md;
    else lo=md+1;
  }
  cout<<"! "<<lo<<endl;
   return 0;
}
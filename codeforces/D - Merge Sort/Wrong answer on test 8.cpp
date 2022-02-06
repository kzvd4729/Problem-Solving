/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2019 15:25                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/873/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],k;
void merg(int lo,int hi,int lt,int rt)
{
  //cout<<lo<<" "<<hi<<" "<<lt<<" "<<rt<<endl;
  if(k==0||lo+1==hi)
  {
    for(int i=lo;i<hi;i++)aa[i]=lt+i-lo;
    return ;
  }
  int md=(lo+hi)/2;
  if(md>lo)
  {
    k--;
    merg(lo,md,rt-(md-lo)+1,rt);
  }
  if(hi>md)
  {
    k--;
    merg(md,hi,lt,lt+(hi-md)-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;if(k%2==0||k>n+n)cout<<-1<<endl,exit(0);
  k--;merg(0,n,1,n);//cout<<k<<endl;
  for(int i=0;i<n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
   return 0;
}
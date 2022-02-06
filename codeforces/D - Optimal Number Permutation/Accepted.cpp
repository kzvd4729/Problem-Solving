/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/30/2018 00:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/622/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   if(n==1)
  {
    cout<<1<<" "<<1<<endl,exit(0);
  }
  int po=1;
  for(int i=1; ;i+=2)
  {
    int on=po,tw=po+(n-i);
    if(aa[on]||aa[tw]||on==tw)break;
    aa[on]=i;aa[tw]=i;po++;
  }
  po=n+1;
  for(int i=2; ;i+=2)
  {
    int on=po,tw=po+(n-i);
    if(aa[on]||aa[tw]||on==tw)break;
    aa[on]=i;aa[tw]=i;po++;
  }
  for(int i=1;i<=n+n;i++)
  {
    if(aa[i]==0)aa[i]=n;
    cout<<aa[i]<<" ";
  }
  cout<<endl;
  return 0;
}
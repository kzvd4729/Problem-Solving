/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 17:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1250/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>aa[10];
    for(int i=1;i<=9;i++)cin>>aa[i];
    int mn=1e8,d=-1;
    for(int i=1;i<=10;i++)
      if(aa[i]<mn)mn=aa[i],d=i;
    //cout<<mn<<endl;
    if(d==10)d=0,cout<<1;
    for(int i=0;i<=mn;i++)
      cout<<d;
    cout<<endl;
  }
  return 0;
}
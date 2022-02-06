/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2019 14:30                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/901/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,f=0;cin>>n;n++;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=2;i<=n;i++)
    if(aa[i-1]>1&&aa[i]>1)f=i;
  if(!f)cout<<"perfect"<<endl,exit(0);
   cout<<"ambiguous"<<endl;
  cout<<0<<" ";int lst=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=aa[i];j++)
      cout<<lst<<" ";
    lst+=aa[i];
  }
  cout<<endl;
  cout<<0<<" ";lst=1;
  for(int i=1;i<=n;i++)
  {
    if(i!=f)
    {
      for(int j=1;j<=aa[i];j++)
        cout<<lst<<" ";
    }
    else
    {
      for(int j=1;j<aa[i];j++)
        cout<<lst<<" ";
      cout<<lst-1<<endl;
    }
    lst+=aa[i];
  }
  cout<<endl;
  return 0;
}
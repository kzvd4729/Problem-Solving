/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 21:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1038/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int mp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,sum=0;cin>>n;
  for(int i=1;i<=n;i++)
    sum+=i;
  int i,f=0;
  for(i=2;i<=sqrt(sum+1);i++)
  {
    if(sum%i==0)
    {
      f=1;break;
    }
  }
  if(f==0)cout<<"No"<<endl,exit(0);
  cout<<"Yes"<<endl;
  cout<<1<<" "<<i<<endl;
  cout<<n-1<<" ";
  for(int j=1;j<=n;j++)
  {
    if(j==i)continue;
    cout<<j<<" ";
  }
  cout<<endl;
   return 0;
}
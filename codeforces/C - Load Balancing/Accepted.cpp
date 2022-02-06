/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2019 18:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/609/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sum=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sum+=x;
    aa[i]=x;
  }
  int mn,mx;
  if(sum%n==0)mn=mx=sum/n;
  else mn=sum/n,mx=(sum/n)+1;
   int a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    a+=max(aa[i]-mx,0);
    b+=max(mn-aa[i],0);
  }
  cout<<max(a,b)<<endl;
  return 0;
}
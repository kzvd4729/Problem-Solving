/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2018 19:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/546/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],n,n1,n2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>n1;
  for(int i=1;i<=n1;i++)
    cin>>a[i];
  cin>>n2;
  for(int i=1;i<=n2;i++)
    cin>>b[i];
  int pt1=n1+1,pt2=n2+1;
  for(int i=1;i<=N;i++)
  {
    if(i>=pt1)
      cout<<i-1<<" "<<2<<endl,exit(0);
    if(i>=pt2)
      cout<<i-1<<" "<<1<<endl,exit(0);
    if(a[i]>b[i])
    {
      a[pt1++]=b[i];
      a[pt1++]=a[i];
    }
    if(a[i]<b[i])
    {
      b[pt2++]=a[i];
      b[pt2++]=b[i];
    }
  }
  cout<<-1<<endl;
  return 0;
}
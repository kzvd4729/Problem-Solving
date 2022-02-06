/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2018 16:53                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/1028/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long n,a[N+2],b[N+2],bit[N+2],lazy[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
 b[1]=a[1];b[2]=b[1]+1;a[n+1]=a[1];
 for(int i=3;i<=n;i++)
 {
  lazy[i-2]=2*a[i-1];
  //for(int j=2;j<i-1;j++)b[j]+=2*a[i-1];
  b[i-1]+=2*a[i-1];b[i]=b[i-1]-a[i-1];
 }
 long ex=(b[n]/a[1]+1)*a[1]+a[n]-b[n];
 for(int i=n;i>=2;i--)
 {
  b[i]+=ex;lazy[i]+=lazy[i+1];
  b[i]+=lazy[i];
 }
 b[n+1]=b[1];
 for(int i=1;i<=n;i++)
  if(b[i]%b[i+1]!=a[i])cout<<"NO"<<endl,exit(0);
 cout<<"YES"<<endl;
 for(int i=1;i<=n;i++)cout<<b[i]<<" ";
 cout<<endl;
 return 0;
}
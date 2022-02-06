/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2020 11:07                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/674/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#define long long long
using namespace std;
const int N=5e3;
int aa[N+2];
void no()
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  int a,b,c,d;cin>>a>>b>>c>>d;
  if(n==4)
  {
    if(k<4)no();
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout<<b<<" "<<a<<" "<<d<<" "<<c<<endl;
    exit(0);
  }
  if(k<n+1)no();
  aa[1]=a;aa[n]=b;aa[2]=c,aa[n-1]=d;
  int id=3;
  for(int i=1;i<=n;i++)
  {
    if(i==a||i==b||i==c||i==d)continue;
    aa[id++]=i;
  }
  for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  cout<<aa[2]<<" "<<aa[1]<<" ";
  for(int i=3;i<=n-2;i++)cout<<aa[i]<<" ";
  cout<<aa[n]<<" "<<aa[n-1]<<endl;
  return 0;
}
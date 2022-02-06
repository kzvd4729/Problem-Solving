/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 20:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/540/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int arr[N+2],sum;
void inv(void)
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,p,x,y,cnt=0;cin>>n>>k>>p>>x>>y;
  for(int i=1;i<=k;i++)
    cin>>arr[i],sum+=arr[i];
  for(int i=k+1;i<=n;i++)
    arr[i]=1,sum++;
  sort(arr+1,arr+n+1);
  int m=(n+1)/2;
  for(int i=m;i<=n;i++)
  {
    if(arr[i]>=y)break;
    if(i-m+1>n-k)inv();
    sum+=y-arr[i-m+1];
    cnt++;
  }
  if(sum>x)inv();
  for(int i=1;i<=cnt;i++)cout<<y<<" ";
  for(int i=cnt+1;i<=n-k;i++)cout<<1<<" ";
  cout<<endl;
   return 0;
}
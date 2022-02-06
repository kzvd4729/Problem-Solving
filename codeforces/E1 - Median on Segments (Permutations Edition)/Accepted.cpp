/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 12:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/1005/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,arr[N+2],k;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  int pos;
  for(int i=1;i<=n;i++)
    if(arr[i]==k)pos=i;
  int sum=0;
  mp[sum]++;
  for(int i=pos+1;i<=n;i++)
  {
    if(arr[i]>k)sum++;
    else sum--;
    mp[sum]++;
  }
  long ans=mp[0]+mp[1];
  sum=0;
  for(int i=pos-1;i>=1;i--)
  {
    if(arr[i]>k)sum++;
    else sum--;
    ans+=mp[0-sum]+mp[1-sum];
  }
  cout<<ans<<endl;
  return 0;
}
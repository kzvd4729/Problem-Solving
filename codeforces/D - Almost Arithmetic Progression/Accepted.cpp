/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 19:00                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 78 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/978/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int arr[N+2],n;
int check(int l,int r)
{
  int tmp[N+2],cnt=0;
  for(int i=1;i<=n;i++)
    tmp[i]=arr[i];
  tmp[1]=arr[1]+l;
  tmp[2]=arr[2]+r;
  int dff=tmp[2]-tmp[1];
  for(int i=3;i<=n;i++)
  {
    if(tmp[i]-tmp[i-1]==dff)continue;
    if(tmp[i]+1-tmp[i-1]==dff)
    {
      cnt++;
      tmp[i]++;
      continue;
    }
    if(tmp[i]-1-tmp[i-1]==dff)
    {
      cnt++;
      tmp[i]--;
      continue;
    }
    return 1e9;
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   if(n<=2)cout<<0<<endl,exit(0);
   int ans=1e9;
  ans=min(ans,check(0,0));
  ans=min(ans,check(0,1)+1);
  ans=min(ans,check(0,-1)+1);
  ans=min(ans,check(1,0)+1);
  ans=min(ans,check(-1,0)+1);
  ans=min(ans,check(1,1)+2);
  ans=min(ans,check(1,-1)+2);
  ans=min(ans,check(-1,1)+2);
  ans=min(ans,check(-1,-1)+2);
   if(ans==1e9)ans=-1;
   cout<<ans<<endl;
   return 0;
}
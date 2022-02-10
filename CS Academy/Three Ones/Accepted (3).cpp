/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10 ms                                           memory_used: 668 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,ans;
string s;
bool ckr(int ln)
{
  int l=1,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='1')cnt++;
    if(i>ln)
    {
      if(s[l-1]=='1')cnt--;
      l++;
      if(cnt<3)return false;
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s;
  int lo=1,hi=n;
  while(hi-lo>3)
  {
    int md=(lo+hi)/2;
    if(ckr(md))hi=md;
    else lo=md;
  }
  for(int md=lo;md<=hi;md++)
  {
    if(ckr(md))cout<<md<<endl,exit(0);
  }
  cout<<n<<endl;
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 22:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1207/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   //int test=(1<<13)+100;
   cout<<"?";int cnt=100,x,ans=0;
  for(int i=0;i<(1<<14);i++)
  {
    if(!cnt)break;
    int f=0;
    for(int j=0;j<7;j++)
      f|=(i&(1<<j));
    if(!f)cout<<" "<<i,cnt--;
  }
  if(cnt)assert(0);
  cout<<endl;fflush(stdout);cin>>x;
  for(int j=0;j<7;j++)
    ans|=(x&(1<<j));
   cout<<"?";cnt=100;
  for(int i=0;i<(1<<14);i++)
  {
    if(!cnt)break;
    int f=0;
    for(int j=7;j<14;j++)
      f|=(i&(1<<j));
    if(!f)cout<<" "<<i,cnt--;
  }
  if(cnt)assert(0);
  cout<<endl;fflush(stdout);cin>>x;
  for(int j=7;j<14;j++)
    ans|=(x&(1<<j));
  cout<<"! "<<ans<<endl;
  fflush(stdout);
  return 0;
}
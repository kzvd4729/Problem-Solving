/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2020 17:32                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 27100 KB                             
*  problem: https://codeforces.com/contest/1280/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int n,m;string s[N+2];
bool c0()
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)if(s[i][j]=='P')return false;
  }
  cout<<0<<"\n";return true;
}
bool c1()
{
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    if(s[i][0]=='P'){cnt++;break;}
  }
  for(int i=0;i<n;i++)
  {
    if(s[i][m-1]=='P'){cnt++;break;}
  }
  for(int j=0;j<m;j++)
  {
    if(s[0][j]=='P'){cnt++;break;}
  }
  for(int j=0;j<m;j++)
  {
    if(s[n-1][j]=='P'){cnt++;break;}
  }
  if(cnt==4)return false;
  cout<<1<<"\n";return true; 
}
bool c2()
{
  if(s[0][0]=='A'||s[0][m-1]=='A'||s[n-1][0]=='A'||s[n-1][m-1]=='A')
  {
    cout<<2<<"\n";return true; 
  }
  return false;
}
bool c3()
{
  for(int i=0;i<n;i++)
  {
    if(s[i][0]=='A'){cout<<3<<"\n";return true;}
  }
  for(int i=0;i<n;i++)
  {
    if(s[i][m-1]=='A'){cout<<3<<"\n";return true;}
  }
  for(int j=0;j<m;j++)
  {
    if(s[0][j]=='A'){cout<<3<<"\n";return true;}
  }
  for(int j=0;j<m;j++)
  {
    if(s[n-1][j]=='A'){cout<<3<<"\n";return true;}
  }
  return false;
}
bool c4()
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)if(s[i][j]=='A'){cout<<4<<"\n";return true;}
  }
  return false;
}
void solve()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
  if(c0())return;
  if(n==1||m==1)
  {
    if(s[0][0]=='A'||s[0][m-1]=='A'||s[n-1][0]=='A'||s[n-1][m-1]=='A')
    {
      cout<<1<<"\n";return ; 
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)if(s[i][j]=='A'){cout<<2<<"\n";return ;}
    }
    cout<<"MORTAL\n";return;
  }
  if(c1())return;
  if(c2())return;
  if(c3())return;
  if(c4())return;
  cout<<"MORTAL\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}
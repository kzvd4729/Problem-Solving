/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 19:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 27100 KB                             
*  problem: https://codeforces.com/contest/1360/problem/F
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
#define long long long
using namespace std;
const int N=1e6;
string s[N+2];
bool ret(string a,int n)
{
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=0;j<a.size();j++)
      cnt+=(a[j]!=s[i][j]);
    if(cnt>1)return false;
  }
  return true;
}
void solve()
{
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i];
   for(int i=0;i<m;i++)
  {
    for(char c='a';c<='z';c++)
    {
      string tmp=s[1];tmp[i]=c;
      if(ret(tmp,n)){cout<<tmp<<endl;return;}
    }
  }
  cout<<-1<<endl;
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
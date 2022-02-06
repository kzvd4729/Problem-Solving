/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/12/2020 11:58                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/132/problem/D
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();s="0"+s;
   for(int i=1;i<=n;i++)p[i]=p[i-1]+(s[i]=='1');
  int mn=p[n],cnt=-1;
  for(int i=n;i>=0;i--)
  {
    if(s[i]=='1'&&cnt==-1)cnt=i;
    if(s[i]=='0'&&cnt!=-1)
    {
      int now=p[i]+cnt-i-(p[cnt]-p[i])+2;
      mn=min(mn,now);
    }
  }
  cout<<mn<<endl;
  if(mn==p[n])
  {
    for(int i=1;i<=n;i++)
      if(s[i]=='1')cout<<"+2^"<<n-i<<'\n';
    exit(0);
  }
  cnt=-1;
  for(int i=n;i>=0;i--)
  {
    if(s[i]=='1'&&cnt==-1)cnt=i;
    if(s[i]=='0'&&cnt!=-1)
    {
      int now=p[i]+cnt-i-(p[cnt]-p[i])+2;
      if(now!=mn)continue;
       for(int j=0;j<i;j++)
      {
        if(s[j]=='1')cout<<"+2^"<<n-j<<'\n';
      }
      cout<<"+2^"<<n-i<<'\n';
      cout<<"-2^"<<n-cnt<<'\n';
      for(int j=i+1;j<cnt;j++)
        if(s[j]=='0')cout<<"-2^"<<n-j<<'\n';
      exit(0);
    }
  }
  assert(0);
  return 0;
}
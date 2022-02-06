/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 20:43                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/1503/problem/A
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 bool ck(string s)
{
  int bl=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='(')bl++;
    else bl--;
    if(bl<0)return false;
  }
  return (bl==0);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    string s;cin>>s;
     int cnt=0;
    for(int i=0;i<n;i++)
      if(s[i]=='0')cnt++;
     if(cnt%2)
    {
      cout<<"NO\n";continue;
    }
    int one=n-cnt;
     string a,b;
    for(int i=0;i<n;i++)a.push_back('a'),b.push_back('a');
     int f=0,now=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='0')
      {
        if(f)a[i]=')',b[i]='(';
        else a[i]='(',b[i]=')';
        f^=1;
      }
      else
      {
        if(now<one/2)
        {
          a[i]='(',b[i]='(';
          now++;
        }
        else a[i]=')',b[i]=')';
      }
    }
    if(ck(a) && ck(b))
    {
      cout<<"YES\n";
      cout<<a<<'\n';
      cout<<b<<'\n';
    }
    else cout<<"NO\n";
  }
  return 0;
}
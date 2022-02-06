/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2020 12:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1451/problem/B
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;
    string s;cin>>s;
     while(q--)
    {
      int l,r;cin>>l>>r;l--,r--;
      int f=0;
      for(int i=r+1;i<s.size();i++)if(s[i]==s[r])f=1;
      for(int i=0;i<l;i++)if(s[i]==s[l])f=1;
      if(f)cout<<"YES\n";else cout<<"NO\n";
    }
  }
  return 0;
}
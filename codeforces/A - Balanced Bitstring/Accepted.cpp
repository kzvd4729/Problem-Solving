/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2020 00:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1404/problem/A
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
    int n,k;cin>>n>>k;string s;cin>>s;
    int f=1;
    for(int i=0;i<k;i++)
    {
      for(int j=i+k;j<n;j+=k)
      {
        if(s[j]=='?')continue;
         if(s[i]=='?')s[i]=s[j];
        else if(s[i]!=s[j])f=0;
      }
    }
    if(f==0||k%2){cout<<"NO\n";continue;}
    int a=0,b=0;
    for(int i=0;i<k;i++)
    {
      if(s[i]=='0')a++;
      else if(s[i]=='1')b++;
    }
    if(a<=k/2&&b<=k/2)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2021 16:31                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 8200 KB                              
*  problem: https://codeforces.com/contest/1537/problem/E1
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
 const int N=1e6,inf=1e9;
  int kmp[N+2];
void doKmp(string s)
{
  int n=s.size();kmp[0]=0;
  for(int i=1;i<n;i++)
  {
    int now=kmp[i-1];kmp[i]=0;
    while(true)
    {
      if(s[now]==s[i]){kmp[i]=now+1;break;}
      if(!now)break;now=kmp[now-1];
    }
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
   string s;cin>>s;
   while(true)
  {
    while((int)s.size()<k)s+=s;
    while((int)s.size()>k)s.pop_back();
        doKmp(s);string ans;
    int f=0;
    for(int i=1;i<k;i++)
    {
      if(s[kmp[i-1]]<s[i])
      {
        f=1;
        s=s.substr(0,i-kmp[i-1]);
        break;
      }
    }
    if(f==0)break;
  }
  cout<<s<<endl;
    return 0;
}
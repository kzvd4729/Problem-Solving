/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 21:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1506/problem/G
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
const int N=1e6,inf=1e9,mod=998244353;
 int ls[26+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;memset(ls,0,sizeof ls);
    int n=s.size();
        for(int i=0;i<n;i++)vs[i]=0,ls[s[i]-'a']=i;
     string pr;
    for( ; ; )
    {
      char mx=(char)('a'-1);
      for(int i=0;i<n;i++)
      {
        if(vs[i])continue;
         mx=max(mx,s[i]);
        if(ls[s[i]-'a']==i)break;
      }
      if(mx<'a')break;
       pr.push_back(mx);
      for(int i=0;i<n;i++)
      {
        if(vs[i])continue;
         if(s[i]!=mx)vs[i]=1;
        else break;
      }
      for(int i=0;i<n;i++)
      {
        if(vs[i])continue;
         if(s[i]==mx)vs[i]=1;
      }
    }
    cout<<pr<<endl;
  }
  return 0;
}
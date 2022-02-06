/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 21:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 900 KB                               
*  problem: https://codeforces.com/contest/1038/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int mp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  string s;cin>>s;
  for(auto x:s)mp[x-'A']++;
   int mn=N+2;
  for(int i=0;i<k;i++)
    mn=min(mn,mp[i]);
  cout<<mn*k<<endl;
   return 0;
}
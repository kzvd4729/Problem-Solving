/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 16:31                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/455/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int trie[N+2][27],nw;
void insrt(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!trie[now][c])trie[now][c]=++nw;
  }
}
int main()
{
  don't compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;insrt(s);
  }
  return 0;
}
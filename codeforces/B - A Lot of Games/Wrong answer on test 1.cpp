/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 17:53                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 10600 KB                             
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
    now=trie[now][c];
  }
}
int grundy(int now)
{
  set<int>st;
  for(int i=0;i<26;i++)
    if(trie[now][i])
      st.insert(grundy(trie[now][i]));
  for(int i=0; ;i++)
    if(st.find(i)==st.end())return i;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;insrt(s);
  }
  int mex=grundy(0);cout<<mex<<endl;
  if(mex)cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}
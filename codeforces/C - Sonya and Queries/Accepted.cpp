/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2018 19:46                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 202 ms                                          memory_used: 50400 KB                             
*  problem: https://codeforces.com/contest/714/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int q,trie[20*100000][3][2],sz;
char ch;
string s;
void insrt(string ss,int vl)
{
  int now=0,z;
  for(auto x:ss)
  {
    z=(x-'0')%2;
    if(!trie[now][z][0])trie[now][z][0]=++sz;
    trie[now][z][1]+=vl;
    now=trie[now][z][0];
  }
}
int query(string ss)
{
  int now=0,sum=0,z;
  for(int i=0;i<ss.size();i++)
  {
    z=(ss[i]-'0')%2;
    if(!trie[now][z][0])
      return sum;
    if(i==ss.size()-1)return trie[now][z][1];
    else now=trie[now][z][0];
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>q;
  while(q--)
  {
    cin>>ch>>s;
    reverse(s.begin(),s.end());
    while(s.size()<18)s.push_back('0');
    if(ch=='+')insrt(s,1);
    else if(ch=='-')insrt(s,-1);
    else cout<<query(s)<<endl;
  }
  return 0;
}
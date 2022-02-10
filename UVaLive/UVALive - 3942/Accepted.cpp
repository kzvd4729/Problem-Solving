/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-17 22:27:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 62                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3942
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=20071027,cn=26;
int nw,trie[400000+4][28],dp[300000+4];
string x,s;
void add()
{
  int now=0;
  for(int i=s.size()-1;i>=0;i--)
  {
    int c=s[i]-'a';
    if(!trie[now][c])trie[now][c]=++nw;
    now=trie[now][c];
  }
  trie[now][cn]=1;
}
void cal(int id)
{
  int now=0;
  for(int i=id;i>0;i--)
  {
    int c=x[i]-'a';
    if(!trie[now][c])return ;
    now=trie[now][c];
    if(trie[now][cn])dp[id]=(dp[id]+dp[i-1])%mod;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tc=0;
  while(cin>>x)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>s;add();
    }
    dp[0]=1;x="#"+x;
    for(int i=1;i<x.size();i++)cal(i);
    cout<<"Case "<<++tc<<": "<<dp[(int)x.size()-1]<<"\n";

    for(int i=0;i<=(int)x.size();i++)dp[i]=0;
    for(int i=0;i<=nw;i++)
      memset(trie[i],0,sizeof(trie[i]));
    nw=0;
  }
  return 0;
}
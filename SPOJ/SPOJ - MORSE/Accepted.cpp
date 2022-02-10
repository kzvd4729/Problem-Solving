/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-28 14:51:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 9.6                             
*  problem: https://vjudge.net/problem/SPOJ-MORSE
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
#define long long long
using namespace std;
const int N=1e6;
string s[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
struct node
{
  int next[2];
}trie[N+2];
int nw,f[N+2];
void insrt(string s)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=0;if(s[i]=='-')c=1;
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  f[now]++;
}
void clear(void)
{
  for(int i=0;i<=nw;i++)
    memset(trie[i].next,0,sizeof trie[i].next),f[i]=0;
  nw=0;
}
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string tx;cin>>tx;int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      string tmp,in;cin>>tmp;
      for(auto x:tmp)
      {
        for(auto c:s[x-'A'])in.push_back(c);
      }
      insrt(in);
    }
    dp[tx.size()]=1;
    for(int i=tx.size()-1;i>=0;i--)
    {
      int now=0;dp[i]=0;
      for(int j=i;j<tx.size();j++)
      {
        int c=0;if(tx[j]=='-')c=1;
        if(trie[now].next[c])now=trie[now].next[c];
        else break;

        dp[i]+=dp[j+1]*f[now];
      }
    }
    cout<<dp[0]<<'\n';clear();
  }
  return 0;
}
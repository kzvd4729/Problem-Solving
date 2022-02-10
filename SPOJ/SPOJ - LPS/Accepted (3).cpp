/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-02 18:27:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 40                                         memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-LPS
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
const int N=1e5;

int sz,last;
struct node
{
  int next[26],len,link;  
}pal[N+2];
void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  sz=1,last=1;
  //last keeps track of the lps suffix of till inserted string
}
void build(string s)
{
  s="#"+s;
  for(int p=1;p<s.size();p++)
  {
    while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
    int x=pal[last].link,c=s[p]-'a';
    while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;//finding suffix link
    if(!pal[last].next[c])
    {
      pal[last].next[c]=++sz;pal[sz].len=pal[last].len+2;
      if(pal[sz].len==1)pal[sz].link=1;
      else pal[sz].link=pal[x].next[c];
    }
    last=pal[last].next[c];
  }
}
int mx;
void dfs(int nd)
{
  mx=max(mx,pal[nd].len);
  for(int i=0;i<26;i++)
    if(pal[nd].next[i])dfs(pal[nd].next[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n;cin>>n;string s;cin>>s;init();
  build(s);dfs(0);dfs(1);cout<<mx<<endl;
  
  return 0;
}
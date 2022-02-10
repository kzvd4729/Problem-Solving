/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-02 18:40:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 4.7                             
*  problem: https://vjudge.net/problem/SPOJ-NUMOFPAL
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

int sz,last,occur[N+2];
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
    last=pal[last].next[c];occur[last]++;
  }
}
void occurrences(void)
{
  for(int i=sz;i>=2;i--)occur[pal[i].link]+=occur[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  string s;cin>>s;init();build(s);occurrences();
  int ans=0;
  for(int i=2;i<=sz;i++)ans+=occur[i];
  cout<<ans<<endl;
  
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-20 19:13:03                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-3518
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
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;

const int mod=1000001011;
const int b=193;
char s[N+2];
int pw[N+2];
void cal(int n)
{
  pw[0]=1;
  for(int i=1;i<=n;i++)
    pw[i]=(1LL*pw[i-1]*b)%mod;
}
struct hsh
{
  vector<int>v;
  int makeHash(int n)
  {
    int hs=0;
    for(int i=0;i<n;i++)
    {
      hs=(1LL*hs*b+s[i])%mod;
      v.push_back(hs);
    }
    return hs;
  }
  int segment(int lt,int rt)
  {
    int x=v[rt];
    if(!lt)return x;
    x=x-(1LL*v[lt-1]*pw[rt-lt+1])%mod;
    if(x<0)x+=mod;return x;
  }
  void clear(void)
  {
    v.clear();
  }
}hs;
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);
  while(true)
  {
    int n;scanf("%s",s);if(s[0]=='#')break;n=strlen(s);
    hs.makeHash(n);

    vector<vector<int> >v;unordered_map<int,int>ii,jj;unordered_set<int>st;
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        int h=hs.segment(i,j);
        if(ii.count(h))ii[h]=max(ii[h],i);
        else ii[h]=i;

        if(jj.count(h))jj[h]=min(jj[h],j);
        else jj[h]=j;

        st.insert(h);
      }
    }
    int ans=0;
    for(auto x:st)ans+=(jj[x]<ii[x]);
    printf("%d\n",ans);hs.clear();
  }
  return 0;
}
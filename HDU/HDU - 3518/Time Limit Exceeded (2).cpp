/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-20 18:55:22                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
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

    vector<vector<int> >v;
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        //cout<<hs.segment(i,j)<<endl;
        v.push_back({hs.segment(i,j),i,j});
      }
    }
    sort(v.begin(),v.end());int ans=0;
    for(int i=0;i<v.size();i++)
    {
      int j;int mn=v[i][2];
      for(j=i+1;j<v.size();j++)
      {
        if(v[i][0]!=v[j][0])break;
        mn=min(mn,v[j][2]);
      }
      j--;
      if(mn<v[j][1])ans++;
      i=j;
    }
    printf("%d\n",ans);hs.clear();
  }
  return 0;
}
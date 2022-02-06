/****************************************************************************************
*  @author: kzvd4729#                                        created: May/30/2020 11:42                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/821/problem/E
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
typedef vector<vector<int> > v2d;
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);//impossible to multiply
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].resize(g,0);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d expo(v2d a,long p)
{
  int n=a.size();if(a[0].size()!=n)assert(0);//impossible
  v2d ret;ret.resize(n);
  for(int i=0;i<n;i++)ret[i].resize(n);
  for(int i=0;i<n;i++)ret[i][i]=1;
  while(p)
  {
    if(p&1)ret=multiply(ret,a);
    a=multiply(a,a);p/=2;
  }
  return ret;
}
int ans[20+2],tmp[N+2];
void print(v2d v)
{
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[0].size();j++)
    {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;long k;cin>>n>>k;ans[1]=1;
  for(int i=1;i<=n;i++)
  {
    long a,b,c;cin>>a>>b>>c;
    if(b>=k)b=k;assert(a!=b);//assert(a<k);
     v2d bs(c+3);//ans[c+3]=0;
    for(int j=0;j<c+3;j++)bs[j].assign(c+3,0);
    bs[0][0]=1;bs[c+3-1][c+3-1]=1;
    for(int j=1;j<c+3-1;j++)
      bs[j][j-1]=1,bs[j][j]=1,bs[j][j+1]=1;
    bs=expo(bs,b-a);
    //print(bs);
     memset(tmp,0,sizeof tmp);
    for(int j=0;j<c+3;j++)
    {
      for(int l=0;l<c+3;l++)
        tmp[j]=(tmp[j]+1LL*bs[j][l]*ans[l])%mod;
    }
    memcpy(ans,tmp,sizeof ans);
    if(b==k)break;
  }
  cout<<ans[1]<<endl;
   return 0;
}
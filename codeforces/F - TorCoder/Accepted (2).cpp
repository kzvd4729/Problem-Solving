/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/11/2020 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2402 ms                                         memory_used: 88500 KB                             
*  problem: https://codeforces.com/contest/240/problem/F
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
#include<random>
#define long long long
using namespace std;
const int N=1e5;
int sg[26+2][N*4+8],lz[26+2][N*4+8];
void pushDown(int id,int nd,int lo,int hi)
{
  if(lz[id][nd]==-1)return ;
  sg[id][nd]=(hi-lo+1)*lz[id][nd];
   if(lo!=hi)
  {
    lz[id][nd*2]=lz[id][nd];
    lz[id][nd*2+1]=lz[id][nd];
  }
  lz[id][nd]=-1;
}
void assign(int id,int nd,int lo,int hi,int lt,int rt,int vl)
{
  pushDown(id,nd,lo,hi);
  if(lo>rt||hi<lt||lt>rt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[id][nd]=vl;pushDown(id,nd,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  assign(id,nd*2,lo,md,lt,rt,vl);
  assign(id,nd*2+1,md+1,hi,lt,rt,vl);
  sg[id][nd]=sg[id][nd*2]+sg[id][nd*2+1];
}
int get(int id,int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  pushDown(id,nd,lo,hi);
  if(lo>=lt&&hi<=rt)return sg[id][nd];
  int md=(lo+hi)/2;
  return get(id,nd*2,lo,md,lt,rt)+get(id,nd*2+1,md+1,hi,lt,rt);
}
int cnt[N+2];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;string s;cin>>s;
  memset(lz,-1,sizeof lz);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<26;j++)
    {
      bool f=((int)(s[i]-'a')==j);
      assign(j+1,1,1,n,i+1,i+1,f);
    }
  }
  while(q--)
  {
    int l,r;cin>>l>>r;int L=l,R=r;
    int f=0,j;
    for(int i=1;i<=26;i++)
    {
      cnt[i]=get(i,1,1,n,l,r);
      if(cnt[i]%2)f++,j=i;
    }
    //for(int i=1;i<=26;i++)cout<<cnt[i];cout<<endl;
    if(f>1)continue;
    for(int i=1;i<=26;i++)
    {
      if(cnt[i]==0)continue;
      assign(i,1,1,n,L,l-1,0);assign(i,1,1,n,r+1,R,0);
      assign(i,1,1,n,l,l+cnt[i]/2-1,1);l=l+cnt[i]/2;
      assign(i,1,1,n,r-cnt[i]/2+1,r,1);r=r-cnt[i]/2;
      assign(i,1,1,n,l,r,0);
    }
    if(f)assign(j,1,1,n,l,r,1);
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=26;j++)
    {
      if(get(j,1,1,n,i,i))cout<<(char)(j-1+'a');
    }
  }
  cout<<endl;
  return 0;
}
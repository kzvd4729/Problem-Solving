/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2020 20:01                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 3525 ms                                         memory_used: 116400 KB                            
*  problem: https://codeforces.com/contest/1093/problem/G
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
using namespace std;
const int N=2e5,inf=1e9;
struct data
{
  int seg[N*4+8];
  void upd(int node,int lo,int hi,int id,int vl)
  {
    if(lo==hi){seg[node]=vl;return;}
    int md=(lo+hi)/2;
    if(id<=md)upd(node*2,lo,md,id,vl);
    else upd(node*2+1,md+1,hi,id,vl);
    seg[node]=max(seg[node*2],seg[node*2+1]);
  }
  int getMax(int node,int lo,int hi,int lt,int rt)
  {
    if(lo>rt||hi<lt)return -inf;
    if(lo>=lt&&hi<=rt)return seg[node];
    int md=(lo+hi)/2;
    return max(getMax(node*2,lo,md,lt,rt),getMax(node*2+1,md+1,hi,lt,rt));
  }
}sg[32+2];
int a[N+2][5+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<k;j++)cin>>a[i][j];
     for(int m=0;m<(1<<k);m++)
    {
      int sm=0;
      for(int j=0;j<k;j++)
      {
        if(m&(1<<j))sm+=a[i][j];
        else sm-=a[i][j];
      }
      sg[m].upd(1,1,n,i,sm);
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id;cin>>id;
      for(int i=0;i<k;i++)
        cin>>b[i];
      for(int m=0;m<(1<<k);m++)
      {
        int sm=0;
        for(int j=0;j<k;j++)
        {
          if(m&(1<<j))sm+=b[j];
          else sm-=b[j];
        }
        sg[m].upd(1,1,n,id,sm);
      }
    }
    else
    {
      int l,r;cin>>l>>r;
      int ans=-inf;
      for(int m=0;m<(1<<k);m++)
        ans=max(ans,sg[m].getMax(1,1,n,l,r)+sg[((1<<k)-1)^m].getMax(1,1,n,l,r));
      cout<<ans<<'\n';
    }
  }
  return 0;
}
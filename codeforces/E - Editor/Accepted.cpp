/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/29/2019 21:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 390 ms                                          memory_used: 52900 KB                             
*  problem: https://codeforces.com/contest/1263/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
 int mn[4*N+200],mx[4*N+200],lazy[4*N+200];
void tooLazy(int node,int lo,int hi)
{
  mn[node]+=lazy[node];mx[node]+=lazy[node];
  if(lo!=hi)lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
  mn[node]=min(mn[node*2],mn[node*2+1]);
  mx[node]=max(mx[node*2],mx[node*2+1]);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
    int p=1,bl=0;
  for(auto x:s)
  {
    if(x=='R')p++;
    else if(x=='L'){p--;p=max(p,1);}
    else if(x=='(')
    {
      upd(1,1,n,p,N,-aa[p]+1);
      bl+=(-aa[p]+1);aa[p]=1;
    }
    else if(x==')')
    {
      upd(1,1,n,p,N,-aa[p]-1);
      bl+=(-aa[p]-1);aa[p]=-1;
    }
    else
    {
      upd(1,1,n,p,N,-aa[p]);
      bl+=(-aa[p]);aa[p]=0;
    }
    //cout<<x;
    //cout<<bl;
    if((bl==0)&&(mn[1]>=0))cout<<mx[1]<<" ";
    else cout<<-1<<" ";
  }
  cout<<endl;
  return 0;
}
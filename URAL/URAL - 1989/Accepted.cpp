/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-11 00:29:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 421                                        memory_used (MB): 7.1                             
*  problem: https://vjudge.net/problem/URAL-1989
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+9,b=39;
long pw[N+2],aa[N+2],bb[N+2];
pair<long,long>seg[4*N+2];
void upd(int node,int lo,int hi,int id,pair<long,long>p)
{
  if(lo==hi)
  {
    seg[node]=p;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,p);
  else upd(node*2+1,md+1,hi,id,p);
  seg[node].first=(seg[node*2].first+seg[node*2+1].first)%mod;
  seg[node].second=(seg[node*2].second+seg[node*2+1].second)%mod;
}
pair<long,long>qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {0,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<long,long>p1=qry(node*2,lo,md,lt,rt);
  pair<long,long>p2=qry(node*2+1,md+1,hi,lt,rt);
  return {(p1.first+p2.first)%mod,(p1.second+p2.second)%mod};
}
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1LL;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*b)%mod;

  string s;cin>>s;int n=s.size();
  for(int i=0;s[i];i++)
    aa[i]=(pw[i]*s[i])%mod;
  int id=0;
  for(int i=s.size()-1;i>=0;i--)
    bb[i]=(pw[id++]*s[i])%mod;
  for(int i=0;s[i];i++)
    upd(1,1,N,i+1,{aa[i],bb[i]});
  int q;cin>>q;
  while(q--)
  {
    string s;cin>>s;
    if(s[0]=='p')
    {
      int lt,rt;cin>>lt>>rt;
      pair<long,long>p=qry(1,1,N,lt,rt);
      p.first=(p.first*bigmod(pw[lt-1],mod-2,mod))%mod;
      p.second=(p.second*bigmod(pw[n-rt],mod-2,mod))%mod;
      if(p.first==p.second)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
    else
    {
      int id;char c;cin>>id>>c;
      upd(1,1,N,id,{pw[id-1]*c,pw[n-id]*c});
    }
  }
  return 0;
}
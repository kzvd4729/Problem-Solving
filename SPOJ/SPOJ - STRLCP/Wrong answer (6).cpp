/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-21 15:25:55                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-STRLCP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,b=617,mod1=1000001011,mod2=1000009999;
int tr,pw1[N+2],pw2[N+2];
struct treap
{
  int lt,rt,dt,pri,sz;
  int hs1,hs2;
}bst[N+2];
void cal(int node)
{
  int l=bst[node].lt,r=bst[node].rt;
  bst[node].sz=bst[l].sz+bst[r].sz+1;

  bst[node].hs1=(1LL*bst[l].hs1*pw1[bst[r].sz+1])%mod1;
  bst[node].hs1=(1LL*bst[node].hs1+1LL*bst[node].dt*pw1[bst[r].sz])%mod1;
  bst[node].hs1=(1LL*bst[node].hs1+bst[r].hs1)%mod1;

  bst[node].hs2=(1LL*bst[l].hs2*pw2[bst[r].sz+1])%mod2;
  bst[node].hs2=(1LL*bst[node].hs2+1LL*bst[node].dt*pw2[bst[r].sz])%mod2;
  bst[node].hs2=(1LL*bst[node].hs2+bst[r].hs2)%mod2;
}
pair<int,int>splitbySize(int node,int ss)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw1[0]=1;
  for(int i=1;i<=N;i++)pw1[i]=(1LL*pw1[i-1]*b)%mod1;
  pw2[0]=1;
  for(int i=1;i<=N;i++)pw2[i]=(1LL*pw2[i-1]*b)%mod2;

  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int root=0,n=s.size();
    for(auto x:s)
    {
      bst[++tr]={0,0,(int)x,rand(),1,(int)x};
      root=join(root,tr);
    }
    int q;cin>>q;
    while(q--)
    {
      char c;cin>>c;
      if(c=='Q')
      {
        int l,r;cin>>l>>r;
        int lo=1,hi=min(n-r,n-l)+1,md;
        while(hi-lo>2)
        {
          md=(lo+hi)/2;
          pair<int,int>p=splitbySize(root,l-1);
          pair<int,int>q=splitbySize(p.second,md);
          int a=bst[q.first].hs1,b=bst[q.first].hs2;
          root=join(q.first,q.second);
          root=join(p.first,root);

          p=splitbySize(root,r-1);
          q=splitbySize(p.second,md);
          int c=bst[q.first].hs1,d=bst[q.first].hs2;
          root=join(q.first,q.second);
          root=join(p.first,root);

          if(a==c&&b==d)lo=md;
          else hi=md;
        }
        for(md=hi;md>=lo;md--)
        {
          pair<int,int>p=splitbySize(root,l-1);
          pair<int,int>q=splitbySize(p.second,md);
          int a=bst[q.first].hs1,b=bst[q.first].hs2;
          root=join(q.first,q.second);
          root=join(p.first,root);

          p=splitbySize(root,r-1);
          q=splitbySize(p.second,md);
          int c=bst[q.first].hs1,d=bst[q.first].hs2;
          root=join(q.first,q.second);
          root=join(p.first,root);

          if(a==c&&b==d)break;
        }
        cout<<md<<"\n";
      }
      else if(c=='R')
      {
        int x;cin>>x>>c;
        pair<int,int>p=splitbySize(root,x-1);
        pair<int,int>q=splitbySize(p.second,1);
        bst[++tr]={0,0,(int)c,rand(),1,(int)c};
        root=join(p.first,tr);
        root=join(root,q.second);
      }
      else
      {
        int x;cin>>x>>c;
        pair<int,int>p=splitbySize(root,x);
        bst[++tr]={0,0,(int)c,rand(),1,(int)c};
        root=join(p.first,tr);
        root=join(root,p.second);
      }
    }
  }
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 44500 KB                             
*  problem: https://codeforces.com/gym/100803/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
  int seg[5*N+2],lazy[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
    lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=ad;tooLazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 1e9;
  if(lo>=lt&&hi<=rt)
    return seg[node];
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;string s;cin>>s;
  set<int>st;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='(')upd(1,1,n,i,n,1);
    else if(s[i-1]==')')
    {
      upd(1,1,n,i,n,-1);st.insert(i);
    }
  }
  while(q--)
  {
    //cout<<s<<endl;
    int x;cin>>x;
    if(s[x-1]=='(')
    {
      s[x-1]=')';st.insert(x);upd(1,1,n,x,n,-2);
      int bg=*st.begin();cout<<bg<<"\n";
      st.erase(bg);s[bg-1]='(';upd(1,1,n,bg,n,2);
    }
    else if(s[x-1]==')')
    {
      st.erase(x);s[x-1]='(';upd(1,1,n,x,n,2);
     // cout<<s<<endl;
    // for(int i=1;i<=n;i++)
    //   cout<<get(1,1,n,i,i)<<" ";
    // cout<<endl;
    // exit(0);
      int lo=1,md,hi=n;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(get(1,1,n,md,n)>=2)hi=md;
        else lo=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(get(1,1,n,md,hi)>=2)break;
      }
      cout<<md<<"\n";
      st.insert(md);s[md-1]=')';upd(1,1,n,md,n,-2);
    }
  }
  return 0;
}
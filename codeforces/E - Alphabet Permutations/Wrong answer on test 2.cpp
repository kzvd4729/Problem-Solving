/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 17:00                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 17600 KB                             
*  problem: https://codeforces.com/contest/610/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
char seg[5*N+2],lz[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  if(lz[node]=='z')return ;seg[node]=lz[node];
  if(lo!=hi)
  {
    lz[node*2]=lz[node];lz[node*2+1]=lz[node];
  }
  lz[node]='z';
}
void upd(int node,int lo,int hi,int lt,int rt,char c)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]=c;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,c);upd(node*2+1,md+1,hi,lt,rt,c);
}
char get(int node,int lo,int hi,int id)
{
  tooLazy(node,lo,hi);
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  if(id<=md)return get(node*2,lo,md,id);
  else return get(node*2+1,md+1,hi,id);
}
int lz2[5*N+2],seg2[5*N+2];
void tooLazy2(int node,int lo,int hi)
{
  if(lz2[node]==-1)return ;seg2[node]=lz2[node];
  if(lo!=hi)
  {
    lz2[node*2]=lz2[node];lz2[node*2+1]=lz2[node];
  }
  lz2[node]=-1;
}
void upd2(int node,int lo,int hi,int lt,int rt,int c)
{
  tooLazy2(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz2[node]=c;tooLazy2(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd2(node*2,lo,md,lt,rt,c);upd2(node*2+1,md+1,hi,lt,rt,c);
}
int get2(int node,int lo,int hi,int id)
{
  tooLazy2(node,lo,hi);
  if(lo==hi)return seg2[node];
  int md=(lo+hi)/2;
  if(id<=md)return get2(node*2,lo,md,id);
  else return get2(node*2+1,md+1,hi,id);
}
int lz3[5*N+2],seg3[5*N+2];
void tooLazy3(int node,int lo,int hi)
{
  if(lz3[node]==-1)return ;seg3[node]=lz3[node];
  if(lo!=hi)
  {
    lz3[node*2]=lz3[node];lz3[node*2+1]=lz3[node];
  }
  lz3[node]=-1;
}
void upd3(int node,int lo,int hi,int lt,int rt,int c)
{
  tooLazy3(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz3[node]=c;tooLazy3(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd3(node*2,lo,md,lt,rt,c);upd3(node*2+1,md+1,hi,lt,rt,c);
}
int get3(int node,int lo,int hi,int id)
{
  tooLazy3(node,lo,hi);
  if(lo==hi)return seg3[node];
  int md=(lo+hi)/2;
  if(id<=md)return get3(node*2,lo,md,id);
  else return get3(node*2+1,md+1,hi,id);
}
map<string,int>mp;bool vis[10+2];
void add(int l,int r,int n,int f)
{
  for(int i=max(l-10,1);i<=r; )
  {
    //cout<<i<<" ";
    string s;memset(vis,0,sizeof(vis));
    for(int j=i;j<=n;j++)
    {
      char c=get(1,1,n,j);if(vis[c-'a'])break;vis[c-'a']=1;
      s.push_back(c);
       if(j>=l)mp[s]+=f;
    }
    i=max(i+1,get2(1,1,n,i)-1);
  }
  //cout<<endl;
}
int cnt[10+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<5*N+2;i++)lz[i]='z',lz2[i]=-1,lz3[i]=-1;
   int n,m,k;cin>>n>>m>>k;string s;cin>>s;
    int lt=1;
  for(int i=2;i<=n;i++)
  {
    if(s[i-1]==s[i-2])continue;
    upd(1,1,n,lt,i-1,s[i-2]);upd2(1,1,n,lt,i-1,i);
    upd3(1,1,n,lt,i-1,lt-1);lt=i;
  }
  upd(1,1,n,lt,n,s[n-1]);upd2(1,1,n,lt,n,n+1);
  upd3(1,1,n,lt,n,lt-1);add(1,n,n,1);
  //cout<<mp["ba"]<<endl;
  while(m--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int l,r;char c;cin>>l>>r>>c;
      add(l,r,n,-1);
       upd(1,1,n,l,r,c);
       int id=get3(1,1,n,l);
      if(id+1<=l-1)upd2(1,1,n,id+1,l-1,l);
       id=get2(1,1,n,r);
      if(r+1<=id-1)upd3(1,1,n,r+1,id-1,id);
       upd2(1,1,n,l,r,r+1);upd3(1,1,n,l,r,l-1);
       add(l,r,n,1);
    }
    else
    {
      // for(int i=1;i<=n;i++)cout<<get(1,1,n,i);
      //   cout<<endl;
      string s;cin>>s;
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<k;i++)
      {
        string tmp;tmp.push_back(s[i]);
        for(int j=i+1;j<k;j++)
        {
          tmp.push_back(s[j]);//cout<<tmp<<endl;
          cnt[tmp.size()]+=mp[tmp];
        }
      }
      cnt[1]=n;int ans=0;
      for(int i=1;i<=k;i++)
      {
        //cout<<cnt[i]<<endl;
        cnt[i]-=2*cnt[i+1];
        ans+=cnt[i];
      }
      cout<<ans<<"\n";
    }
  }
  return 0;
}
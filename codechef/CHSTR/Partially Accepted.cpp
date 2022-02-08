/****************************************************************************************
*  @author: kzvd4729                                         created: 31-10-2018 15:03:24                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.65 sec                                        memory_used: 17.4M                                
*  problem: https://www.codechef.com/problems/CHSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long mod=1e9+7;
int length,sz,last,occur[N+N+2];
long fac[N+2];
string s;
vector<int>v_len[N+N+2];
struct automata
{
  int len,link,fpo;
  int next[26];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;st[now].fpo=st[now].len;
  int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].len=st[p].len+1;
      st[cl].fpo=st[q].len;
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
void count_occurrence(void)
{
  for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
  for(int i=length;i>=1;i--)
  {
    for(int j=0;j<v_len[i].size();j++)
    {
      int tmp=v_len[i][j];
      occur[st[tmp].link]+=occur[tmp];
    }
  }
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
long ncr(long n,long r)
{
  long ret=fac[n];
  ret=(ret*bigmod(fac[r],mod-2,mod))%mod;
  ret=(ret*bigmod(fac[n-r],mod-2,mod))%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1LL;
  for(int i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
  int t;cin>>t;
  while(t--)
  {
    int q;cin>>length>>q;cin>>s;
    for(int i=0;i<=length+length;i++)
    {
      st[i].len=0;st[i].link=0;
      memset(st[i].next,0,sizeof(st[i].next));
      v_len[i].clear();
      occur[i]=0;
    }
    sz=0,last=0;st[0].link=-1;
    for(int i=0;i<length;i++)insrt(s[i]-'a');
    count_occurrence();
//    for(int i=1;i<=sz;i++)
//      cout<<occur[i]<<" "<<endl;
    while(q--)
    {
      int x;cin>>x;
      long ans=0;
      for(int i=1;i<=sz;i++)
      {
        if(occur[i]<x)continue;
        ans=(ans+ncr(occur[i],x)*(st[i].len-st[st[i].link].len))%mod;
      }
      cout<<ans%mod<<endl;
    }
  }
  return 0;
}
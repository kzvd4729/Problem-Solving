/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 19:49                        
*  solution_verdict: Runtime error on test 7                 language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 150600 KB                            
*  problem: https://codeforces.com/gym/101550/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
#define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
const int N=5e5;
const int mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
int pw1[N+2],pw2[N+2];
void cal(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(1LL*pw1[i-1]*b1)%mod1;
    pw2[i]=(1LL*pw2[i-1]*b2)%mod2;
  }
}
struct hsh
{
  string s;vector<pair<int,int> >v;
  pair<int,int>makeHash(void)
  {
    int hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(1LL*hs1*b1+x)%mod1;
      hs2=(1LL*hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<int,int>segment(int lt,int rt)
  {
    int x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=x-(1LL*v[lt-1].first*pw1[rt-lt+1])%mod1;
    y=y-(1LL*v[lt-1].second*pw2[rt-lt+1])%mod2;
    if(x<0)x+=mod1;if(y<0)y+=mod2;
    return {x,y};
  }
  void clear(){v.clear();}
}hs[N+2],tmp;
 int sz,trie[N+2][26][2];
void insrt(string &s,int id)
{
  int now=0,c;
  for(auto &x:s)
  {
    c=x-'a';
    if(!trie[now][c][0])
    {
      if(sz==N)assert(0);
      trie[now][c][0]=++sz,trie[now][c][1]=id;
    }
    now=trie[now][c][0];
  }
}
int match(int i)
{
  int lo=0,hi=min((int)tmp.s.size(),(int)hs[i].s.size())-1,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(tmp.segment(0,md)==hs[i].segment(0,md))lo=md;
    else hi=md;
  }
  int mt=-1;
  for(md=lo;md<=hi;md++)
    if(tmp.segment(0,md)==hs[i].segment(0,md))mt=md;
  return mt;
}
string ss[N+2];
int qry(string &s)
{
  //SP(s);
  tmp.clear();tmp.s=s;tmp.makeHash();
  int now=0,c,cnt=0;
  for(int i=0;i<s.size();i++)
  {
    //SP(i);
    c=s[i]-'a';
    if(!trie[now][c][0])return cnt+s.size()-i;
     int mt=match(trie[now][c][1]);
    //cout<<i<<" -- "<<mt<<endl,getchar();
    //cout<<i<<" -- "<<trie[now][c][1]<<endl;getchar();
    cnt+=min(mt-i+1,(int)ss[trie[now][c][1]].size()-mt+1);
    //cout<<"**"<<min(mt-i+1,(int)ss[trie[now][c][1]].size()-mt)<<endl;
    //cout<<i<<" -- "<<mt<<endl;getchar();
     for( ;i<=mt;i++)
    {
      c=s[i]-'a';
      now=trie[now][c][0];
    }
    i--;
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>ss[i];hs[i].s=ss[i];hs[i].makeHash();
    insrt(ss[i],i);
  }
  string x;
  //SP(n);SP(q);
  while(q--)
  {
    cin>>x;cout<<qry(x)<<"\n";
  }
  return 0;
}
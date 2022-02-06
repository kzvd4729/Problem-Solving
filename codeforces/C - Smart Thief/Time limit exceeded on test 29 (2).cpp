/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/30/2019 19:45                        
*  solution_verdict: Time limit exceeded on test 29          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 41200 KB                             
*  problem: https://codeforces.com/gym/102001/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
//..............................................................................
/*
de bruijn sequence: given an integer n and alphabet size k. there are total k^n
distinct string possible. find a string of length k^n+n-1(minimum length)
where every of those k^n string present as substring.
complexity: k^n*n*lgn
*/
//substring length n and alphabet 0 to k-1;
vector<string>v;
void generate(int n,int k,string s)
{
  if(n==0){v.push_back(s);return ;}
  for(int i=0;i<k;i++)
  {
    s.push_back((char)(i+'0'));
    generate(n-1,k,s);s.pop_back();
  }
}
map<string,int>mp;map<int,string>rv;
vector<int>adj[N+2];
int in[N+2],out[N+2];vector<int>cir;
bool eulerCircuit(int n,int start)
{
  for(int i=1;i<=n;i++)if(in[i]!=out[i])return false;
  stack<int>st;st.push(start);
  while(!st.empty())
  {
    int u=st.top();
    if(adj[u].size()==0){cir.push_back(u);st.pop();}
    else {st.push(adj[u].back());adj[u].pop_back();}
  }
  reverse(cir.begin(),cir.end());return true;
}
void solveEuler(int n)//adj graph is given
{
  for(int i=1;i<=n;i++){for(auto x:adj[i])out[i]++,in[x]++;}
  eulerCircuit(n,1);
}
string solve(int n,int k)
{
  string s;generate(n-1,k,s);
  for(int i=0;i<v.size();i++)
    mp[v[i]]=i+1,rv[i+1]=v[i];
  for(auto x:v)
  {
    string s=x;reverse(s.begin(),s.end());s.pop_back();
    reverse(s.begin(),s.end());
     int u=mp[x];
    for(int i=0;i<k;i++)
    {
      s.push_back((char)(i+'0'));
      adj[u].push_back(mp[s]);s.pop_back();
    }
  }
  //cout<<v.size()<<endl;
  solveEuler(v.size());string ret=rv[cir[0]];
  //cout<<cir.size()<<endl;
  for(int i=1;i<cir.size();i++)
    ret.push_back(rv[cir[i]][n-2]);
  return ret;
}
int ch[12];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  void clear(void)
  {
    v.clear();
  }
}h;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;int ln=k+n-1;
   for(int i=0;i<m;i++)cin>>ch[i];
   if(n==1)
  {
    for(int i=0;i<k;i++)
      cout<<ch[i];
    cout<<endl,exit(0);
  }
   int f=0,pw=1;
  for(int i=1;i<=n;i++)
  {
    pw*=m;if(pw>600000){f=1;break;}
  }
  if(!f&&n<=30)
  {
    string s=solve(n,m);//cout<<s.size()<<endl;
    if(s.size()<ln)exit(0);
    for(int i=0;i<ln;i++)
      cout<<ch[s[i]-'0'];
    cout<<endl;
  }
  else
  {
    cal(N);
    while(true)
    {
      h.s.clear();
      for(int i=0;i<ln;i++)
        h.s.push_back((char)(ch[rng()%m]+'0'));
      h.makeHash();set<pair<int,int> >st;
      int f=0;
      for(int i=n-1;i<ln;i++)
      {
        st.insert(h.segment(i-(n-1),i));
        if(st.size()<=i-(n-1)){f=1;break;}
      }
      if(!f)cout<<h.s<<endl,exit(0);
      h.clear();
    }
  }
  return 0;
}
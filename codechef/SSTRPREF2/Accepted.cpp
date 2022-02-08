/****************************************************************************************
*  @author: kzvd4729                                         created: 19-10-2021 16:55:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.24 sec                                        memory_used: 44.2M                                
*  problem: https://www.codechef.com/SNCKQL21/problems/SSTRPREF2
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6+10,inf=1e9;
/* single hash */
const int mod=1000001011;
const int b=193;//greater than maximum value
int pw[N+2];
void calPower()
{
  pw[0]=1;
  for(int i=1;i<=N;i++)
    pw[i]=(1LL*pw[i-1]*b)%mod;
}
struct hsh
{
  vector<int>v;string s;
  void init(string _s)
  {
    v.clear();s=_s;
  }
  int makeHash()
  {
    int hs=0;
    for(auto x:s)
    {
      hs=(1LL*hs*b+x)%mod;
      v.push_back(hs);
    }
    return hs;
  }
  int segment(int lt,int rt)
  {
    int x=v[rt];if(!lt)return x;
    x=x-(1LL*v[lt-1]*pw[rt-lt+1])%mod;
    if(x<0)x+=mod;return x;
  }
}p,q,x;
int kmp[N+N+2];
void doKmp(string s)
{
  int n=s.size();kmp[0]=0;
  for(int i=1;i<n;i++)
  {
    int now=kmp[i-1];kmp[i]=0;
    while(true)
    {
      if(s[now]==s[i]){kmp[i]=now+1;break;}
      if(!now)break;now=kmp[now-1];
    }
  }
}
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;calPower();
  while(t--)
  {
    string S1,S2,X;cin>>S1>>S2>>X;
    p.init(S1);p.makeHash();
    q.init(S2);q.makeHash();
    x.init(X);x.makeHash();
    for(int i=0;i<=(int)S1.size()+1;i++)qm[i]=-1;
    string s=S1+"#"+X;
    doKmp(s);
    //cout<<s<<endl;
    for(int i=0;i<=(int)X.size();i++)
    {
      int lo=1,hi=(int)X.size(),md,l=0;
      while(lo<=hi)
      {
        md=(lo+hi)/2;
        if(x.segment(i,i+md-1)==q.segment(0,md-1) && (i+md-1<(int)X.size()) && 
            (md-1<(int)S2.size()))
        {
          l=md;lo=md+1;
        }
        else hi=md-1;
      }
      int c=kmp[i+S1.size()];
      //cout<<c<<" * "<<l<<endl;
      qm[c]=max(qm[c],l); 
    }
    for(int i=(int)S1.size();i>=1;i--)
      qm[kmp[i-1]]=max(qm[kmp[i-1]],qm[i]);
    //for(int i=0;i<=(int)S1.size();i++)cout<<qm[i]<<" ";cout<<endl;
    long ans=0;
    for(int i=0;i<=(int)S1.size();i++)ans+=qm[i]+1;
    cout<<ans<<endl;
  }
  return 0;
}
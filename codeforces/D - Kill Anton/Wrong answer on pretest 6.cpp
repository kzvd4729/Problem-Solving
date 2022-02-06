/****************************************************************************************
*  @author: * kzvd4729                                       created: May/28/2021 21:22                        
*  solution_verdict: Wrong answer on pretest 6               language: GNU C++17 (64)                          
*  run_time: 139 ms                                          memory_used: 17000 KB                             
*  problem: https://codeforces.com/contest/1526/problem/D
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
const int N=1e6,inf=1e9,mod=1000000007;
 int cnt[26+2],n;
vector<int>po[26+2];
  long bit[2][N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=n;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
long getRange(int lo,int hi)
{
  return get(hi)-get(lo-1);
}
void addRange(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
  int ck(string a)
{
  int ret=0;
  for(int i=(int)a.size()-1;i>=0;i--)
  {
    int p=po[a[i]-'A'].back();
    po[a[i]-'A'].pop_back();
     ret+=getRange(p+1,n);addRange(p,p,-1);
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;n=s.size();
     vector<char>v;memset(cnt,0,sizeof cnt);
    for(auto x:s)v.push_back(x),cnt[x-'A']++;
      sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
      //cout<<"YEE"<<endl;
     //for(auto x:v)cout<<x<<endl;
     int mx=-1;string ans;
    do
    {
      for(int i=1;i<=n;i++)bit[0][i]=0,bit[1][i]=0;
              //memset(bit,0,sizeof bit);
      addRange(1,n,1);
      for(int i=0;i<26;i++)po[i].clear();
       string b;int now=0;
      for(auto x:v)
      {
        for(int i=1;i<=cnt[x-'A'];i++)
        {
          po[x-'A'].push_back(++now);
          b.push_back(x);
        }
      }
      int cur=ck(s);
      if(cur>mx)mx=cur,ans=b;
     }while(next_permutation(v.begin(),v.end()));
      //cout<<mx<<" "<<ans<<endl;
    cout<<ans<<'\n';
  }
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2020 21:44                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 280 ms                                          memory_used: 51000 KB                             
*  problem: https://codeforces.com/contest/17/problem/E
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
#define long long long 
using namespace std;
const int N=2e6;
 //od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
long st[N+2],ed[N+2];
void addtional(int n)//n=s.size();
{
  for(int i=0;i<n;i++)
    st[i-od[i]/2]++,st[i+1]--,ed[i]++,ed[i+od[i]/2+1]--;
  for(int i=0;i<n-1;i++)
    st[i-ev[i]/2+1]++,st[i+1]--,ed[i+1]++,ed[i+1+ev[i]/2]--;
  for(int i=1;i<n;i++)st[i]+=st[i-1],ed[i]+=ed[i-1];
}
const long mod=51123987;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  string s;cin>>s;manacher(s);addtional(s.size());
   long tt=0;
  for(int i=0;i<s.size();i++)tt+=od[i]/2+1;
  for(int i=0;i<s.size()-1;i++)tt+=ev[i]/2;
   tt%=mod;
  tt=tt*(tt-1);tt%=mod;tt=(tt*25561994LL)%mod;
   for(int i=s.size()-2;i>=0;i--)st[i]+=st[i+1];
  long ans=0;
  for(int i=0;i<s.size()-1;i++)ans=(ans+(ed[i]%mod)*(st[i+1]%mod))%mod;
    tt=(tt-ans)%mod;
    cout<<(tt+mod)%mod<<endl;
     return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2020 19:22                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1169 ms                                         memory_used: 24000 KB                             
*  problem: https://codeforces.com/contest/985/problem/F
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
const int N=2e5,p=11000027,mod=1000001011;
int pw[N+2],qm[26+2][N+2],inv[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(1LL*pw[i-1]*p)%mod;
  for(int i=0;i<=N;i++)inv[i]=big(pw[i],mod-2);
   int n,m;cin>>n>>m;
  string s;cin>>s;s="#"+s;
   for(int c=0;c<26;c++)
  {
    for(int i=1;i<=n;i++)
    {
      qm[c][i]=qm[c][i-1];
      if((int)(s[i]-'a')==c)
        qm[c][i]=(qm[c][i]+pw[i])%mod;
    }
  }
  while(m--)
  {
    int a,b,c;cin>>a>>b>>c;
    vector<int>v1,v2;
    for(int i=0;i<26;i++)
    {
      int tmp=(qm[i][a+c-1]-qm[i][a-1]+mod)%mod;
      tmp=(1LL*tmp*inv[a-1])%mod;
      v1.push_back(tmp);
    }
    for(int i=0;i<26;i++)
    {
      int tmp=(qm[i][b+c-1]-qm[i][b-1]+mod)%mod;
      tmp=(1LL*tmp*inv[b-1])%mod;
      v2.push_back(tmp);
    }
    sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
     if(v1==v2)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}
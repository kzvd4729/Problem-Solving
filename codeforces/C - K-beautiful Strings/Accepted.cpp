/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/06/2021 21:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1493/problem/C
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
const int N=2e5,inf=1e9,mod=1e9+7;
 int fr[N+2],rq,k;
void dl(int i)
{
  rq-=(k-fr[i]%k)%k;
  fr[i]--;
  rq+=(k-fr[i]%k)%k;
}
void add(int i)
{
  rq-=(k-fr[i]%k)%k;
  fr[i]++;
  rq+=(k-fr[i]%k)%k; 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>k;
    string s;cin>>s;
    if(n%k){cout<<-1<<'\n';continue;}
     rq=0;for(int i=0;i<26;i++)fr[i]=0;
    for(auto x:s)
    {
      int i=x-'a';add(i);
    }
    if(rq==0){cout<<s<<'\n';continue;}
     string ans="-1";int f=0;
    for(int i=n-1;i>=0;i--)
    {
      char in=s[i];dl(in-'a');
      for(char c=in+1;c<='z';c++)
      {
        add(c-'a');
         if(rq<=n-(i+1))
        {
          f=1;ans.clear();
          for(int j=0;j<i;j++)ans.push_back(s[j]);
          ans.push_back(c);
          int ln=ans.size();
           string tmp;
          for(int j=0;j<26;j++)
          {
            while(fr[j]%k)
            {
              tmp.push_back((char)(j+'a'));
              fr[j]++;ln++;
            }
          }
          for(int j=ln+1;j<=n;j++)tmp.push_back('a');
          sort(tmp.begin(),tmp.end());
          ans+=tmp;
          break;
        }
        dl(c-'a');
      }
      if(f)break;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
/****************************************************************************************
*  @author: * kzvd4729                                       created: May/01/2020 21:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1348/problem/C
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int fr[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;string s;cin>>s;
    memset(fr,0,sizeof fr);
    for(auto x:s)fr[x-'a']++;
    sort(s.begin(),s.end());
     int f=-1,l=-1,c=0;
    for(int i=0;i<26;i++)
    {
      if(fr[i]==0)continue;
      l=i;if(f==-1)f=i;c++;
    }
    if(f==l)
    {
      int rq=(fr[f]+k-1)/k;
      while(rq--)cout<<(char)(f+'a');
      cout<<"\n";continue;
    }
    if(fr[f]<k)
    {
      cout<<s[k-1]<<"\n";continue;
    }
    if(c>2||fr[f]>k)
    {
      for(int i=k-1;i<s.size();i++)cout<<s[i];
        cout<<"\n";continue;
    }
    for(int i=1;i<=fr[f]/k;i++)
      cout<<(char)(f+'a');
    int rq=(fr[l]+k-1)/k;
    while(rq--)cout<<(char)(l+'a');
    cout<<"\n";
  }
  return 0;
}
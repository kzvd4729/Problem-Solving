/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 15 ms                                           memory_used: 740 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  long k;cin>>k;
  if(s.size()==1)
  {
    cnt[s[0]-'a']++;
  }
  else
  {
    for(long i=1;i<s.size()-1;i++)
    {
      long c=s[i]-'a';
      cnt[c]+=(1<<k);
    }
    long c,p;c=s[0]-'a';
    if(k<=2)p=k+1;else p=(1LL<<(k-1))+1;
    cnt[c]+=p;
    c=s.back()-'a';p=(1LL<<(k-1));
    cnt[c]+=p;
  }
  cout<<cnt[0];
  for(long i=1;i<26;i++)cout<<" "<<cnt[i];
    cout<<endl;
  return 0;
}